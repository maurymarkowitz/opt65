    .ORG $8000
    JMP (forward_addr)
    LDA #$42
forward_addr:
    .WORD forward_label
forward_label:
    RTS
