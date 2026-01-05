opt65 design notes
==================

**Copyright © 2026 Maury Markowitz**

[![GPL license](http://img.shields.io/badge/license-GPL-brightgreen.svg)](https://opensource.org/licenses/gpl-license)

## Purpose

opt65 is the result of an effort to rewrite the article on the [WDC 65C02](https://en.wikipedia.org/wiki/WDC_65C02), the not-well-known successor to the original MOS 6502. Shortly after the 6502 was released, the design team broke up and moved on to other efforts. Bill Mench opened the Western Design Center, or WDC, to offer 6502-based custom systems. His customers later asked him to lay out a CMOS implementation of the original NMOS design, and during this process they also added several new instructions.

While writing the article, the question arose of how much the new instructions really helped. Articles from the era suggested the code could be anywhere to 10 to 20% smaller with these changes. But the list of new features was relatively small, and that seemed unrealistic for real-world examples. This led me to consider writing a [RetroBASIC](https://github.com/maurymarkowitz/RetroBASIC)-like system for 6502 assembler, to explore these changes and possibly suggest others.

## A real example

Having been an Atari 400 owner in the past, the original operating system and BASIC for this platform seemed like a good target to run these sorts of tests on. It turns out that the assembler used for BASIC was quite odd, even by standards of the day, and the code is marked up in ways that will need some more work to properly parse. This meant the operating system, written in Microtek's PDP-11 cross-compiler, became the primary target.

Running the 1.0 version on this code reveals some useful information. For instance:

* of the 100 JMP instructions, 33 are "short" and can be replaced by a BRA on the 65C02
* of the 245 JSR's, 51 are short and could be replaced - but the 65C02 did not include this
* there are a number of instructions with a #0 immediate that might be replaced by a new opcode, but...
** 84 of those are loads to A, X or Y. This strongly suggests LZA/LZX/LZY opcodes would be very useful
** and the other possibilities, like CAZ, are too rarely seen to be useful

In all, when you look at possible basic optimizations of the original code, replacing some instructions with the new 65C02 versions, and imagining a version with BRS and LZA/LZX/LZY, the code would become about 5% shorter. Considering only those opcodes in the real 65C02, that is closer to 3%. Nothing to turn up your nose at, that's 300 bytes that can be put to good use, but certainly not the sort of numbers being claimed in the original articles.

## Sources and inspiration

As the concept developed, conversations with like-minded retrocomputer enthusiasts led to a search for similar programs. This led to three that have influenced opt65:

* opt65 by Daniel Dallmann, https://hitmen.c02.at/files/cc65/opt65.c

opt65 was suggested to me on the [retrocomputing forum](https://retrocomputingforum.com/t/6502-65c02-65ce02-assembly-updater/5113). It is a peephole optimizer that looks for a number of common programming issues. This inspired me to add similar tests to *my* opt65, a name I had selected before I learned of Daniel's code. Dan's code is more powerful than mine, it runs a data analysis to look, for exmaple, values that are loaded and then saved to the same location, which is beyond the scope of my code. There are also a number of simpler tests, like a TAX followed by a TXA that can be replaced by a TXA, or useless code like ORA #0, which have been added. These, unsurprisingly, are quite rare, but still worth looking for, and have been added to this program.

* Lin6 by Devine Lu Linvega, https://git.sr.ht/~rabbits/lin6

Lin6 is a pure "linter", which looks for style problems in the original source code. It re-formats assembler into a pretty-print version with a cannonical layout for the ASM6 assembler. This is not directly applicable to opt65, but did inspire the desire to add a similar pretty-print output feature.

* Nice65 by Andrew Dunai, https://github.com/and3rson/nice65

Nice65 is similar in concept to Lin6, but is written in Python using Lark and supports many different dialects. Inspired by this code, the first versions of opt65 were also written in Python using Lark, but I found the results less than satifying. The use of cursor.ai reduced the coding overhead of flex/bison to the point where the advantages of the much simpler Python code were largely wiped away. However, Nice65 supports a number of dialects that have one-off features that will be added to opt65 over time.
