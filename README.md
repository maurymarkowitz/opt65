# 6502 Assembler

A 6502 assembler written in Flex and Bison.

## Building

Make sure you have `flex`, `bison`, and `gcc` installed:

```bash
make
```

This will create the `asm65` executable.

## Usage

```bash
./asm65 input.asm [output.bin]
```

If no output file is specified, it will create a `.bin` file with the same name as the input file.

## Features

### Instructions

All standard 6502 instructions are supported:
- Arithmetic: ADC, SBC
- Logical: AND, ORA, EOR
- Shifts: ASL, LSR, ROL, ROR
- Comparisons: CMP, CPX, CPY, BIT
- Load/Store: LDA, LDX, LDY, STA, STX, STY
- Branches: BCC, BCS, BEQ, BMI, BNE, BPL, BVC, BVS
- Jumps: JMP, JSR
- Stack: PHA, PHP, PLA, PLP
- Registers: TAX, TAY, TSX, TXA, TXS, TYA
- Increment/Decrement: INC, INX, INY, DEC, DEX, DEY
- Flags: CLC, CLD, CLI, CLV, SEC, SED, SEI
- Other: BRK, NOP, RTI, RTS

### Addressing Modes

- Implied (e.g., `NOP`, `RTS`)
- Accumulator (e.g., `ASL`)
- Immediate (e.g., `LDA #$42`)
- Absolute (e.g., `LDA $1000`)
- Zero Page (e.g., `LDA $42`)
- Indexed (e.g., `LDA $1000,X`, `LDA $1000,Y`)
- Zero Page Indexed (e.g., `LDA $42,X`)
- Indirect (e.g., `JMP ($1000)`)
- Indirect Indexed (e.g., `LDA ($42,X)`, `LDA ($42),Y`)
- Relative (e.g., `BEQ label`)

### Directives

- `.ORG address` - Set the origin address
- `.BYTE value` - Emit a byte
- `.WORD value` - Emit a word (little-endian)
- `.RES count` - Reserve bytes

### Labels

Labels are defined with a colon:
```
start:
    LDA #$00
    STA $2000
    JMP start
```

## Example

Create a file `test.asm`:

```asm
    .ORG $8000

start:
    LDA #$42
    STA $2000
    JMP start
```

Assemble it:
```bash
./asm65 test.asm
```

This will create `test.bin` with the assembled code.

## Notes

- Numbers can be decimal (e.g., `42`) or hexadecimal (e.g., `$2A`)
- Labels are case-insensitive
- Comments start with `;` and continue to the end of the line
- The assembler performs a single pass, so forward references may not work correctly for all cases

