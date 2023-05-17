#line 1 "C:/Users/Scabecini/Documents/mikroC PROjects/MyP1.c"
void main() {
 TRISB = 0x00;
 PORTB = 0x00;

 while(1){
 PORTB = 0b000000001;
 }
}
