
_main:

;MyP1.c,1 :: 		void main() {
;MyP1.c,2 :: 		TRISB = 0x00; //ob00000000 PORTB as OUTPUT
	CLRF       TRISB+0
;MyP1.c,3 :: 		PORTB = 0x00;
	CLRF       PORTB+0
;MyP1.c,5 :: 		while(1){
L_main0:
;MyP1.c,6 :: 		PORTB = 0b000000001;
	MOVLW      1
	MOVWF      PORTB+0
;MyP1.c,7 :: 		}
	GOTO       L_main0
;MyP1.c,8 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
