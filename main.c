#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "stats.h"

#define VERSION "1.0.0"

extern uint8_t output[65536];
extern uint16_t pc;
extern uint16_t org_address;
extern int yyparse(void);
extern int yylex(void);
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

void print_usage(const char *progname) {
    printf("Usage: %s [OPTIONS] <input.asm> [output.bin]\n", progname);
    printf("\nOptions:\n");
    printf("  -o <file>          Specify output file name\n");
    printf("  -h, --help         Print this help message\n");
    printf("  -v, --version      Print version information\n");
    printf("  -n, --no-code      Don't save the binary output file\n");
    printf("  -s, --suggestions  Print individual 65C02 replacement suggestions\n");
    printf("  -p, --print-stats  Print statistics (without individual suggestions)\n");
    printf("\nExamples:\n");
    printf("  %s program.asm\n", progname);
    printf("  %s -o output.bin program.asm\n", progname);
    printf("  %s -s program.asm\n", progname);
    printf("  %s -p -n program.asm\n", progname);
}

void print_version(void) {
    printf("asm65 - 6502/65C02 Assembler\n");
    printf("Version %s\n", VERSION);
}

int main(int argc, char *argv[]) {
    char *input_file = NULL;
    char *output_file = NULL;
    int no_code = 0;
    int show_suggestions = 0;
    int print_stats = 0;
    int opt;
    
    /* Parse command line options */
    while ((opt = getopt(argc, argv, "o:hvnsp-:")) != -1) {
        switch (opt) {
            case 'o':
                output_file = optarg;
                break;
            case 'h':
                print_usage(argv[0]);
                return 0;
            case 'v':
                print_version();
                return 0;
            case 'n':
                no_code = 1;
                break;
            case 's':
                show_suggestions = 1;
                break;
            case 'p':
                print_stats = 1;
                break;
            case '-':
                /* Long options */
                if (strcmp(optarg, "help") == 0) {
                    print_usage(argv[0]);
                    return 0;
                } else if (strcmp(optarg, "version") == 0) {
                    print_version();
                    return 0;
                } else if (strcmp(optarg, "no-code") == 0) {
                    no_code = 1;
                } else if (strcmp(optarg, "suggestions") == 0) {
                    show_suggestions = 1;
                } else if (strcmp(optarg, "print-stats") == 0) {
                    print_stats = 1;
                } else {
                    fprintf(stderr, "Unknown option: --%s\n", optarg);
                    print_usage(argv[0]);
                    return 1;
                }
                break;
            case '?':
                print_usage(argv[0]);
                return 1;
        }
    }
    
    /* Get input file from remaining arguments */
    if (optind >= argc) {
        fprintf(stderr, "Error: No input file specified\n");
        print_usage(argv[0]);
        return 1;
    }
    
    input_file = argv[optind];
    
    /* If output file not specified and not using -o, use default */
    if (!output_file && optind + 1 < argc) {
        output_file = argv[optind + 1];
    }
    
    stats_set_filename(input_file);
    
    FILE *input = fopen(input_file, "r");
    if (!input) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", input_file);
        return 1;
    }
    
    yyin = input;
    extern char *yyfilename;
    yyfilename = input_file;
    
    extern int pass;
    extern uint16_t pc;
    extern uint16_t org_address;
    extern uint8_t output[];
    extern int symbol_count;
    
    /* Pass 1: Build symbol table */
    pass = 1;
    pc = 0;
    org_address = 0;
    stats_init();  /* Reset stats for pass 1 */
    if (yyparse() != 0) {
        fprintf(stderr, "Parse error: %s at line %d\n", yytext, yylineno);
        fclose(input);
        return 1;
    }
    
    /* Reset for pass 2 */
    rewind(input);
    extern int yylineno;
    yylineno = 1;
    
    /* Pass 2: Generate code */
    pass = 2;
    pc = 0;
    org_address = 0;
    extern uint16_t min_address;
    extern uint16_t max_address;
    min_address = 0xFFFF;  /* Reset min/max tracking */
    max_address = 0;
    memset(output, 0, sizeof(output));
    stats_init();  /* Reset stats for pass 2 (but keep symbol table) */
    if (yyparse() != 0) {
        fprintf(stderr, "Parse error: %s at line %d\n", yytext, yylineno);
        fclose(input);
        return 1;
    }
    
    fclose(input);
    
    /* Determine output filename if not specified */
    int output_file_allocated = 0;
    if (!output_file) {
        /* Change .asm to .bin */
        output_file = malloc(strlen(input_file) + 5);
        strcpy(output_file, input_file);
        char *ext = strrchr(output_file, '.');
        if (ext) {
            strcpy(ext, ".bin");
        } else {
            strcat(output_file, ".bin");
        }
        output_file_allocated = 1;
    }
    
    /* Write output unless -n flag is set */
    if (!no_code) {
        FILE *out = fopen(output_file, "wb");
        if (!out) {
            fprintf(stderr, "Error: Cannot create output file '%s'\n", output_file);
            if (output_file_allocated) free(output_file);
            return 1;
        }
        
        /* Calculate binary size using actual min/max addresses where code was emitted */
        extern uint16_t min_address;
        extern uint16_t max_address;
        uint16_t actual_min = (min_address == 0xFFFF) ? org_address : min_address;
        uint16_t actual_max = (max_address == 0) ? (pc > 0 ? pc - 1 : org_address) : max_address;
        int binary_size = actual_max - actual_min + 1;
        
        if (binary_size <= 0) {
            fprintf(stderr, "Error: Invalid address range (min=%d, max=%d, org_address=%d, pc=%d)\n", 
                    actual_min, actual_max, org_address, pc);
            fclose(out);
            if (output_file_allocated) free(output_file);
            return 1;
        }
        
        /* Write from actual_min to actual_max */
        if (fwrite(output + actual_min, 1, binary_size, out) != binary_size) {
            fprintf(stderr, "Error: Failed to write output file\n");
            fclose(out);
            if (output_file_allocated) free(output_file);
            return 1;
        }
        
        fclose(out);
        printf("Assembled successfully: %d bytes written to '%s'\n", 
               binary_size, output_file);
        stats_set_binary_size(binary_size);
    } else {
        /* Calculate binary size using actual min/max addresses where code was emitted */
        extern uint16_t min_address;
        extern uint16_t max_address;
        uint16_t actual_min = (min_address == 0xFFFF) ? org_address : min_address;
        uint16_t actual_max = (max_address == 0) ? (pc > 0 ? pc - 1 : org_address) : max_address;
        int binary_size = actual_max - actual_min + 1;
        
        if (binary_size <= 0) {
            fprintf(stderr, "Error: Invalid address range (min=%d, max=%d, org_address=%d, pc=%d)\n", 
                    actual_min, actual_max, org_address, pc);
            return 1;
        }
        printf("Assembled successfully: %d bytes (not saved)\n", 
               binary_size);
        stats_set_binary_size(binary_size);
    }
    
    /* Print statistics based on flags */
    if (print_stats || show_suggestions) {
        stats_print_report_custom(print_stats, show_suggestions);
    } else {
        /* Default: print everything */
        stats_print_report();
    }
    
    if (output_file_allocated) free(output_file);
    return 0;
}

