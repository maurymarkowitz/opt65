opt65 Manual
============

**Copyright © 2026 Maury Markowitz**

Version 1.2.0

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Table of Contents

* [Introduction](#introduction)
* [Installation](#installation)
* [Building from Source](#building-from-source)
* [Usage](#usage)
* [Output](#output)
* [Supported Dialects](#supported-dialects)
* [Limitations](#limitations)
* [Examples](#examples)

## Introduction

opt65 is a 6502/65C02 assembly language parser and optimizer. Unlike traditional assemblers, opt65 is purpose-built for **code analysis and optimization suggestions** rather than production assembly. It parses assembly source code, generates a binary for validation purposes, and produces detailed statistics about the code's structure and optimization opportunities.

The program performs a two-pass assembly process:
1. **Pass 1**: Parses the input file and builds a symbol table
2. **Pass 2**: Generates binary code with all symbols resolved

opt65 is particularly useful for:
- Understanding code composition and instruction usage patterns
- Discovering optimization opportunities in existing 6502 codebases
- Evaluating the impact of upgrading from 6502 to 65C02 opcodes
- Analyzing legacy assembly code from retrocomputers

The program has several sections of output. By default, it produces:

* **Basic statistics** about the source code and generated binary
* **Opcode frequency** listing showing which instructions are used and how often
* **Summary section** with code metrics and optimization statistics

Command-line switches enable additional output sections:

* **Optimization suggestions** for the original 6502 code (redundant instructions, etc.)
* **65C02 suggestions** with line-by-line code replacement recommendations
* **Zero-parameter optimizations** showing where immediate #0 can be replaced

## Installation

### Binary Installation

Pre-built binaries are available for macOS (Intel and Apple Silicon), Linux, and Windows at:

https://github.com/maurymarkowitz/opt65/releases

**macOS and Linux:**

Install via Homebrew:
```sh
brew tap maurymarkowitz/tap https://github.com/maurymarkowitz/homebrew-tap
brew install maurymarkowitz/tap/opt65
```

**macOS with custom prefix:**
```sh
brew install maurymarkowitz/tap/opt65 --prefix=/opt/homebrew
```

**Windows:**

Install via Scoop:
```powershell
scoop bucket add maurymarkowitz https://github.com/maurymarkowitz/scoop-bucket
scoop install opt65
```

### Manual Installation

1. Download the appropriate binary from the [Releases](https://github.com/maurymarkowitz/opt65/releases) page
2. Extract to a directory in your PATH
3. Verify installation: `opt65 -h`

## Building from Source

### Prerequisites

- **GCC** or **Clang** C compiler
- **Flex** (lexical analyzer generator)
- **Bison** (parser generator)
- **GNU Make**

These are generally available on macOS and most Unix systems, but will have to be manually installed on Windows.

### macOS

```sh
brew install flex bison
cd opt65
make clean
make
sudo make install PREFIX=/usr/local
```

**Note**: On Apple Silicon Macs, Homebrew installs to `/opt/homebrew`:
```sh
make install PREFIX=/opt/homebrew
```

### Linux (Ubuntu/Debian)

```sh
sudo apt-get update
sudo apt-get install -y build-essential flex bison
cd opt65
make clean
make
sudo make install
```

### Linux (Fedora/RHEL)

```sh
sudo dnf install -y gcc flex bison make
cd opt65
make clean
make
sudo make install
```

### Windows (MSYS2/MinGW64)

```bash
# In MSYS2 terminal
pacman -S mingw-w64-x86_64-toolchain flex bison make
cd opt65
make clean RM="rm -f"
make CC=x86_64-w64-mingw32-gcc
make install PREFIX="C:\Program Files\opt65"
```

### Build Options

**Debug build with symbols:**
```sh
make DEBUG=1
```

**Clean build:**
```sh
make clean
make
```

**Install to custom location:**
```sh
make install PREFIX=/usr/local
```

**Uninstall:**
```sh
sudo make uninstall PREFIX=/usr/local
```

## Usage

### Basic Command Line

```
opt65 [OPTIONS] <input.asm> [output.bin]
```

### Options

| Option | Description |
|--------|-------------|
| `-h, --help` | Display help message and exit |
| `-v, --version` | Display version information and exit |
| `-o <file>` | Specify output binary filename |
| `-n, --no-code` | Don't generate binary output (stats only) |
| `-s, --suggestions` | Print detailed 65C02 replacement suggestions (line-by-line) |
| `-p, --print-stats` | Print statistics report without optimization suggestions |

### Default Behavior

When run without `-p` or `-s`, opt65 prints the full report including:
- Source code statistics
- Binary code statistics
- Opcode usage frequency
- Summary statistics (all optimization categories)

### Examples

**Basic analysis, generates binary and full report:**
```sh
opt65 input.asm
```

**Show detailed 65C02 replacement suggestions:**
```sh
opt65 -s input.asm
```

**Statistics only, no binary output:**
```sh
opt65 -n -p input.asm
```

**Specify custom output filename:**
```sh
opt65 -o program.bin input.asm
```

**Analyze without generating binary:**
```sh
opt65 -n input.asm
```

## Output

### Example Output

```
Assembled successfully: 10240 bytes written to 'atari.bin'

Source Code Statistics
  Input file:               atari.asm
  Lines of code:            10933
  Actual code lines:        8245
  
Symbol Statistics
  Total symbols:            342
  Labels:                   287
  Variables:                55
  Undefined symbols:        0

Binary Code Statistics
  Starting address:         0xE000
  Ending address:           0xFFFF
  Code bytes:               10240
  Empty pages:              2
  
Opcode Frequencies (top 10)
  LDA                       1247
  STA                        942
  JSR                        534
  BCC                        421
  RTS                        387
  LDX                        356
  STX                        298
  EOR                        267
  CMP                        245
  INX                        213

Summary Statistics
  6502 Instructions:        8934
  65C02 Upgrades Available: 342 (3.8%)
  JMP to BRA replacements:  33
  Zero-page optimizations:  84
  Redundant instructions:   12
  
Recommended for 65C02 Upgrade: YES
  Estimated size reduction:  2.5%
```

### Output Sections Explained

**Source Code Statistics:**
- `Lines of code`: Total lines in the assembly file
- `Actual code lines`: Lines containing actual instructions (excludes comments, blanks)

**Symbol Statistics:**
- `Total symbols`: Number of defined labels and variables
- `Undefined symbols`: References to undefined symbols (errors)

**Binary Code Statistics:**
- `Code bytes`: Size of generated binary in bytes
- `Empty pages`: Number of 256-byte pages with no code (gaps in address space)

**Opcode Frequencies:**
- Shows the most-used instructions in descending order
- Helps identify optimization hot spots

**Summary Statistics:**
- `6502 Instructions`: Total instruction count
- `65C02 Upgrades Available`: Number of instructions that could be replaced with 65C02-specific opcodes
- `JMP to BRA replacements`: Short JMPs that could become relative branches (65C02)
- `Zero-page optimizations`: LDA/LDX/LDY with #0 that could use hypothetical LZA/LZX/LZY opcodes
- `Redundant instructions`: Patterns like TAX/TXA that could be optimized

## Supported Dialects

opt65 primarily targets the **Microtek PDP-11 cross-assembler** dialect used for the Atari operating system and similar 1980s systems. This includes support for:

- Standard 6502/65C02 mnemonics
- **Labels**: Symbols followed by colons (e.g., `LOOP:`)
- **Comments**: Semicolon-prefixed text (e.g., `; comment here`)
- **Pseudo-ops**: ORG, EQU, DS, DB, DW (basic support)
- **Addressing modes**: All standard 6502/65C02 modes (immediate, address, absolute, indexed, indirect, etc.)
- **Symbol references**: Numeric and alphanumeric labels with forward references

### Limited Support

The following features have partial or incomplete support:

- **Macros**: Recognized but not fully expanded
- **Conditional assembly**: Not currently supported
- **String literals**: Basic support
- **Non-ASCII characters**: Detected and warned about

See the [Limitations](#limitations) section for details.

## Limitations

### Known Issues

1. **Parser conflicts**: The grammar contains 12 shift/reduce and 86 reduce/reduce conflicts in the Bison parser. This is documented but typically doesn't cause issues for well-formed assembly.

2. **Incomplete dialect support**: Some early assembler features (especially from the Atari BASIC assembler) are not fully recognized and will cause parse errors.

3. **No macro expansion**: Macro definitions are parsed but not expanded inline.

4. **No conditional assembly**: IF/ENDIF and similar directives are not supported.

5. **Symbol scope**: All symbols are global; local labels are not supported.

6. **Pass 2 validation**: Errors in Pass 2 (such as undefined symbols in branch targets) may not be fully diagnostic.

### Workarounds

- For problematic source files, try manually expanding macros or conditional blocks
- Comment out unsupported directives temporarily to parse the rest of the code
- Use the design notes to understand what dialects are partially supported

## Examples

### Example 1: Analyzing the Atari Operating System

```sh
$ opt65 atari-os.asm -p

Source Code Statistics
  Input file:               atari-os.asm
  Lines of code:            10933
  Actual code lines:        8245

Binary Code Statistics
  Code bytes:               10240

Summary Statistics
  6502 Instructions:        8934
  65C02 Upgrades Available: 342 (3.8%)
  JMP to BRA replacements:  33
  Estimated size reduction:  3.1%
```

This shows that upgrading the Atari OS from 6502 to 65C02 would save approximately 318 bytes (3.1%), which could be significant in a 64KB system.

### Example 2: Getting Line-by-Line 65C02 Suggestions

```sh
$ opt65 program.asm -s

Line 245: LDA #0       → LDA (hypothetical LZA would be 1 byte instead of 2)
Line 367: CMP #0       → CPZ (hypothetical; CMP #0 is common)
Line 892: JMP LABEL    → BRA LABEL (BRA is shorter for branches < 127 bytes)
```

### Example 3: Statistics-Only Analysis

```sh
$ opt65 program.asm -n -p
# Generates no binary file, only prints statistics
```

### Example 4: Custom Output Filename

```sh
$ opt65 -o build/output.bin src/firmware.asm
# Reads from src/firmware.asm
# Writes binary to build/output.bin
# Prints standard statistics
```

## Troubleshooting

### "Error: Cannot open input file"

**Cause**: Input file not found or not readable.

**Solution**: 
- Verify the filename and path: `ls -la filename.asm`
- Ensure file is readable: `chmod +r filename.asm`
- Try absolute path if relative path fails

### "Parse error ... at line 123"

**Cause**: Assembly syntax not recognized by opt65.

**Solution**:
- Check line 123 for unusual assembly directives or syntax
- Try simplifying or removing problematic lines
- Check if it's a dialect not fully supported by opt65
- Verify the assembler syntax is compatible with Microtek-style assembly

### "Error: Cannot create output file"

**Cause**: Cannot write to output directory.

**Solution**:
- Check directory permissions: `ls -la outputdir/`
- Ensure no read-only files with the same name exist
- Try writing to a different directory (e.g., `/tmp`)

### Binary file is larger than expected

**Cause**: opt65 writes all bytes between the minimum and maximum instruction addresses, filling gaps.

**Solution**:
- This is expected behavior—use `-n` flag if you only want statistics
- Post-process the binary with external tools to remove gaps if needed

## See Also

- [Design Notes](opt65%20design.md) - Background and philosophy behind opt65
- [GitHub Repository](https://github.com/maurymarkowitz/opt65) - Source code and issue tracking
- [RetroBASIC](https://github.com/maurymarkowitz/RetroBASIC) - Similar project for BASIC dialect analysis
