    .ORG $8000
    JMP later_label
    LDA #$42
    STA $1000
later_label:
    RTS
