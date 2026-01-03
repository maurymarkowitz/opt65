    .ORG $8000
start:
    LDA #$42
    BEQ start
    BNE start
    BCC start
    BCS start
    BMI start
    BPL start
    BVC start
    BVS start
    BRA start
    RTS
