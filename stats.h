#ifndef STATS_H
#define STATS_H

#include <stdint.h>

/* Initialize statistics tracking */
void stats_init(void);

/* Record an opcode being emitted */
void stats_record_opcode(uint8_t opcode);

/* Print statistics report */
void stats_print_report(void);

/* Print statistics report with custom options */
void stats_print_report_custom(int print_stats, int show_suggestions);

/* Get count for a specific opcode */
int stats_get_count(uint8_t opcode);

/* Record a zero constant transfer to register */
void stats_record_zero_to_register(const char *instruction);

/* Record a zero constant transfer to memory */
void stats_record_zero_to_memory(const char *instruction, uint16_t address);

/* Check if an opcode is a 65C02 instruction */
int stats_is_c02_opcode(uint8_t opcode);

/* Get count of 65C02 opcodes */
int stats_get_c02_count(void);

/* Record instruction with context for replacement analysis */
void stats_record_instruction(uint8_t opcode, const char *instr_name, uint16_t operand, int line_num, const char *filename, const char *expression);

/* Set current filename for tracking */
void stats_set_filename(const char *filename);

/* Set total binary size for statistics */
void stats_set_binary_size(int size);

#endif /* STATS_H */

