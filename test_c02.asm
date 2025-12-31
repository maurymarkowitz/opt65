    .ORG $8000

start:
    LDA #$42
    STA $2000
    STZ $2001
    PHX
    PHY
    BRA start

