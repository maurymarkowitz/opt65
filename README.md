opt65
=====

**Copyright © 2026 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Contents

* [Introduction](#introduction)
* [Installing opt65](#installing-opt65)
* [Building opt65](#building-opt65)
* [Running opt65](#running-opt65)
* [Examples](#examples)

## Introduction

opt65 is a 6502/65C02 assembly language parser and optimizer. It is purpose-built for analyzing assembly code rather than production assembly. Unlike traditional assemblers, opt65 focuses on **code analysis and optimization suggestions** rather than just producing binaries.

The tool parses 6502/65C02 assembly code from early Microtek cross-assembler dialects (such as the Atari operating system source) and generates detailed statistics about the code structure, instruction usage patterns, and optimization opportunities. It performs a two-pass assembly process to build a symbol table and then generate code, ensuring the parser is working correctly while providing the binary output as a validation artifact.

opt65 analyzes your code to:
- Identify optimization opportunities in 6502 code (redundant instructions, inefficient patterns)
- Suggest upgrades to 65C02-specific opcodes that could reduce code size
- Report statistics on code composition and opcode usage
- Detect potential improvements like replacing short JMPs with BRA instructions

The tool includes an extensive manual (see `docs/opt65 manual.md`) for detailed instructions, supported dialects, and troubleshooting.

## Installing opt65

The latest source code and prebuilt binaries are available at:

https://github.com/maurymarkowitz/opt65/releases

Binary packages are provided for macOS, Linux, and Windows.

### macOS and Linux

On macOS and Linux, you can use Homebrew:

```sh
brew tap maurymarkowitz/tap https://github.com/maurymarkowitz/homebrew-tap
brew install maurymarkowitz/tap/opt65
```

**Note**: Homebrew installs to `/opt/homebrew/bin` on Apple Silicon Macs instead of `/usr/local/bin`.

### Windows

On Windows, you can use Scoop:

```powershell
scoop bucket add maurymarkowitz https://github.com/maurymarkowitz/scoop-bucket
scoop install opt65
```

### Manual Installation

1. Download the appropriate binary from the [Releases](https://github.com/maurymarkowitz/opt65/releases) page
2. Extract the ZIP archive
3. Move the `opt65` executable to a location in your PATH (e.g., `/usr/local/bin` on macOS/Linux, or `C:\Program Files\opt65\bin` on Windows)
4. Verify installation by running `opt65 -h`

## Building opt65

You can also build opt65 from source. It is a simple makefile project that works on any Unix-like system (macOS, Linux) and Windows (via MinGW).

### Prerequisites

- C compiler: `gcc` or `clang`
- `make`
- `flex` (lexical analyzer generator)
- `bison` (parser generator)

### Building on macOS

```sh
brew install flex bison
make
```

This creates the `opt65` executable in the current directory.

### Building on Linux

**Ubuntu/Debian:**
```sh
sudo apt-get update
sudo apt-get install -y build-essential flex bison
make
```

**Fedora/RHEL:**
```sh
sudo dnf install -y gcc flex bison make
make
```

### Building on Windows

Windows compatibility is provided using MinGW. Install MinGW if you haven't already, then:

```bash
# Using MSYS2 MinGW64 terminal
pacman -S mingw-w64-x86_64-toolchain flex bison make
cd opt65
make clean RM="rm -f"
make CC=x86_64-w64-mingw32-gcc
```

### Installation from Source

Both Unix and Windows support `make install`, which installs the binary and documentation to the proper system locations:

```sh
make install
```

To specify a custom installation prefix (defaults to `/usr/local` on Unix, `C:\Program Files\opt65` on Windows):

```sh
make install PREFIX=/opt/opt65
```

To uninstall:

```sh
make uninstall PREFIX=/opt/opt65
```

## Running opt65

opt65 is used to analyze assembly files and generate statistics and optimization suggestions. Basic usage:

```sh
opt65 [OPTIONS] <input.asm> [output.bin]
```

If no output filename is specified, opt65 will create a `.bin` file with the same name as the input file.

### Command-line Options

- `-h, --help` - Display help message
- `-v, --version` - Display version information  
- `-o <file>` - Specify output binary filename
- `-n, --no-code` - Don't save the binary output file (statistics only)
- `-s, --suggestions` - Print detailed line-by-line 65C02 replacement suggestions
- `-p, --print-stats` - Print statistics without optimization suggestions

### Default Behavior

When run without `-p` or `-s`, opt65 prints the complete report including source code statistics, binary code metrics, opcode frequencies, and summary analysis of optimization opportunities.

## Examples

### Basic Analysis

Analyze an assembly file and generate both binary output and statistics:

```sh
opt65 firmware.asm
```

This reads `firmware.asm`, generates `firmware.bin`, and prints a detailed report showing code statistics, opcode usage, and optimization suggestions.

### Show Detailed 65C02 Suggestions

View line-by-line optimization recommendations for upgrading from 6502 to 65C02:

```sh
opt65 -s program.asm
```

### Statistics Only (No Binary)

Analyze code without generating binary output:

```sh
opt65 -n -p firmware.asm
```

### Custom Output File

Specify a different binary filename:

```sh
opt65 -o build/output.bin src/firmware.asm
```

### Real-world Example

Analyze the Atari operating system source to evaluate 65C02 upgrade potential:

```sh
opt65 atari-os.asm -p
```

This would show how many bytes could be saved by upgrading to 65C02 instructions, helping determine if the upgrade effort is worthwhile.

## Documentation

For more comprehensive documentation, see:

- **[opt65 Manual](docs/opt65%20manual.md)** - Complete reference with installation instructions, output descriptions, supported dialects, and troubleshooting
- **[Design Notes](docs/opt65%20design.md)** - Background, philosophy, and research behind opt65

## See Also

- [RetroBASIC](https://github.com/maurymarkowitz/RetroBASIC) - Similar project analyzing BASIC dialect code
