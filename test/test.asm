    .ORG $8000
start:
    LDA #$42
    STA $1000
    JMP start
