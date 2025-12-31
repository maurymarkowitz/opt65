    .ORG $8000

    PATSIZ EQU $1
    LOMEM = $80
    ARGSTK = $80
    
    .EQU TEST1 $42
    TEST2 EQU $43
    TEST3 = $44

start:
    LDA #PATSIZ
    LDA #LOMEM
    LDA #TEST1
    LDA #TEST2
    LDA #TEST3
