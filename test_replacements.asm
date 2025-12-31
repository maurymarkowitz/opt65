    .ORG $8000

start:
    LDA #$42
    STA $2000
    LDA #0
    STA $2001
    TAX
    PHA
    PLA
    TAY
    JMP nearby
nearby:
    LDA #0
    STA $2002
    JMP start

