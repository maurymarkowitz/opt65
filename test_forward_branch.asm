    .ORG $8000
    BEQ forward_label
    LDA #$42
forward_label:
    RTS
