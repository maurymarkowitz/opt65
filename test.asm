    .ORG $8000

start:
    LDA #$42
    STA $2000
    LDA #$00
    STA $2001
    JMP start

