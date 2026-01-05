opt65
=====

**Copyright © 2026 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Introduction

opt65 is a 6502 parser that collects statistics about the source code and uses them to suggest changes to improve it. This includes tests for redundant code, JMPs that can be branches, and similar optimizations.

It also looks for examples of code that can be replaced by new instructions in the 65c02, and can optionally print a detailed list of the individual replacements.

Future expansions will expand the suggestions to include 65ce02 opcodes, and a pretty-printer. Command line switches are subject to change!

opt65 currently understands several early assembler dialects, but the main target was the Microtek cross-assembler running on the PDP-11.

## Building

Make sure you have `flex`, `bison`, and `gcc` or `clang` installed:

`make`

This will create the `opt65` executable.

## Usage

```
./opt65 [OPTIONS] <input.asm> [output.bin]
```

### Options

- `-h, --help` - Print help message
- `-v, --version` - Print version information
- `-o <file>` - Specify output file name
- `-n, --no-code` - Don't save the binary output file
- `-s, --suggestions` - Print individual 65C02 replacement suggestions

### Examples

```
# Basic usage - creates input.bin
./opt65 input.asm

# Show detailed optimization suggestions
./opt65 -s input.asm

# Show statistics only (no suggestions)
./opt65 -p input.asm

# Assemble without saving binary
./opt65 -n -s input.asm
```

If no output file is specified, it will create a `.bin` file with the same name as the input file.
