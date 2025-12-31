    .ORG $8000
    .PAGE
    .TITLE 'TEST'
    LIST S
    *= $9000
    ASCZER = '0
    COLON = $3A
start:
    LDA #ASCZER
