#if !defined(_AVR_ATmega328P_)

#endif

#include "Uart.h"

#define _BV(bit) (1 << (bit))
#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define loop_until_bit_is_set(sfr, bit) do { } while (bit_is_clear(sfr, bit))
#define loop_until_bit_is_clear(sfr, bit) do { } while (bit_is_set(sfr, bit))


void Uart_Init(void) {

    Uart_SetBaudRate(9600);

    
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);//enable the transmitter and reciever registors

    /* 8 data bits, 1 stop bit */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void Uart_SetBaudRate(unsigned short BuadRate)
{
    unsigned short UBBR = ( (F_CPU / 16) /  BuadRate ) - 1;//
    UBRR0L = (UBBR & 0xFF);
    UBRR0H = (( UBBR >> 8 ) & 0xFF);//to use the last two bits in the UBRR high
}


void Uart_SendChar(unsigned char DataByte)//function the holds the value for UCSR0A registor 
{
    // Wait until Write buffer is empty
    while ( ! (UCSR0A & ( 1 << UDRE0)) );
    UDR0 = DataByte;
}

unsigned char Uart_ReadData(void) {
    // Wait until data is received
    while ( ! (UCSR0A & ( 1 << RXC0)) );
    return UDR0;
}

void Uart_SendString(const char DataString[]){
    int i;
    for (i=0; DataString[i]; i++)//increment data string by 1
    {
        Uart_SendChar(DataString[i]);//recall send character function
    }
}