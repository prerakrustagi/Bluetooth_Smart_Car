#include <avr/io.h>
#include <avr\interrupt.h>

void init_usart(char a);

ISR(USART_RXC_vect);

int main(void) {
  DDRB = 0xff;
  init_usart(51);
  sei();
  while(1);
}

void init_usart(char a) {
  UBRRL = a;
  UBRRH = 0x00;
  UCSRC = (1<<UCSZ1) | (1<<UCSZ0) | (1<<URSEL);
  UCSRB = (1<<RXEN) | (1<<RXCIE);
}

ISR(USART_RXC_vect) {
  char dir;
  dir = UDR;
  switch(dir) {
    case 'A' : PORTB=0b00000101; break;
    case 'B' : PORTB=0b00001010; break;
    case 'C' : PORTB=0b00000100; break;
    case 'D' : PORTB=0b00000001; break;
    case 'E' : PORTB = 0b00000000; break;
  }
}
