    .ORG $8000
    JMP forward_label
    JSR forward_label
    LDA #$42
forward_label:
    RTS
