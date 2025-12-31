PATSIZ   EQU     $1          ; PATCH AREA SIZE
ZICB     EQU     $20         ; zero PageIOCB
ZPG1     EQU     $80         ; beginning of BASIC's zero page
MISCR1   EQU     $480        ; syntax check, etc.
MISCRAM  EQU     $500        ; OTHER ram USAGE

CIO      EQU     $E456       ; in OS ROMs
IOCBORG  EQU     $340        ; where IOCBs start
DCBORG   EQU     $300        ; where DCB (for SIO) is

ROM      EQU     $A000       ; begin code here
ZFP      EQU     $D2         ; begin fltg point work area

CR       EQU     $9B         ; ATASCII end of line

LMADR    EQU     $2E7        ; system lo mem
HMADR    EQU     $2E5        ; system high mem
HIMEM    EQU     HMADR

FPORG    EQU     $D800       ; fltg point in OS ROMs
BRKBYT   EQU     $11
WARMFL   EQU     $08         ; warmstart flag
RNDLOC   EQU     $D20A       ; get a random byte here
CRTGI    EQU     $BFFC-3     ; cartridge init vector
EPCHAR   EQU     $5D         ; the "?" for INPUT statement
