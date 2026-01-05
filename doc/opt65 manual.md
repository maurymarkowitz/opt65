opt65 Manual
============

**Copyright © 2026 Maury Markowitz**

Version 1.0.0

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Introduction

opt65 is a 6502 assembler that is dedicated to collecting and displaying statistics about the assembler code. It is not really intended to be used as a production assembler, the conversion from assembler to binary is intended primarily as a way to ensure the parser is valid.

The program has several sections of output. Normally it will always produce:

* Basic statistics about the source code and the binary it produces
* A list of the opcodes used and the number of times they appear

Command line switches can be used to produce several additional sections:

* A list of possible optimizations in the original 6502 code
* A list of opcodes that use an immediate #0 operand
* A list of possible replacements of 6502 with 65C02 opcodes

And, if 65C02 conversion is of interest:

* A list of line-by-line code replacements for the 65C02 suggestions

The last item is not currently usable directly, it is a human-readable form, and will likely be re-implemented in a `diff`-compatible format.
