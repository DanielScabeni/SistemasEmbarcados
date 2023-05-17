void main() {
     TRISB.f0 = 0; //ob00000000 PORTB as OUTPUT
     PORTB.f0 = 0;
     
     while(1){
     PORTB.f0 = 1; //0b000000001
     }
}