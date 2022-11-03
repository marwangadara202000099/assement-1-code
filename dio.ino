#include <avr/io.h>

#define SetBit(Reg,Pin) (Reg |= (1<<Pin))//Function that access regsiter and set pin 
#define ClearBit(Reg,Pin) (Reg &=~ (1<<Pin))//Function that clear pin in the register
#define ToggleBit(Reg,Pin) (Reg ^= (1<<Pin))//Change the pin the the register if its 0 to 1 or 1 to 0
#define GetBit(Reg,Pin) (Reg&(1<<Pin))//function to get the value on the pin of the register
#include "dio.h"

void Dio_SetPinDirection(unsigned char DDRX, unsigned char Pin,unsigned char Direction){//function takes values for DDR, pin in the DDR, either output or input
  switch (DDRX)//switch cas function
  {
    
       case 'B'://registor B (DDRB)
    if (Direction == 1)//1==output
    {
      SetBit(DDRB,Pin);//set DDRB and Pin number
     
    }
    else{
      ClearBit(DDRB,Pin);    //clear Pin and DDRB 
      
    }
    break;
        case 'C':// DDRC
    if (Direction == 1)//output
    {
      SetBit(DDRC,Pin); //set DDRC and Pin number
      
    }
    else{
      ClearBit(DDRC,Pin);//clear Pin and DDRC
      
    }
    break;
        case 'D'://DDRD
    if (Direction == 1)//output
    {
      SetBit(DDRD,Pin); //set DDRD and Pin number
      
    }
    else{
      ClearBit(DDRD,Pin);//clear Pin and DDRD  
      
    }
    break;//once condition ends it'll break out of the IF condition
}
}
unsigned char Dio_GetPinState(unsigned char Port,unsigned char pin){//function to read port and pin value
  int BitValue;
  switch(Port){//swicth case
    
    case 'B':
    BitValue = GetBit(PORTB,pin);//shows if PORTB is output or input
    break;
    case 'C':
    BitValue = GetBit(PORTC,pin);//shows if PORTC is output or input
    break;
    case 'D':
    BitValue = GetBit(PORTD,pin);//shows if PORTD is output or input
    break;
  }
  return BitValue;
}
void Dio_SetPortDirection(unsigned char PORTX, unsigned char Pin,unsigned char Direction){//function takes values for Port, pin in the Port, either output or input
  switch (PORTX)
  {
    
       case 'B':
    if (Direction == 1)//Setting port as output
    {
      SetBit(PORTB,Pin);//Setting PortB and pin number as output       
     
    }
    else{
      ClearBit(PORTB,Pin);//Clear PortB and Pin number       
      
    }
    break;
        case 'C':
    if (Direction == 1)
    {
      SetBit(PORTC,Pin); //Setting PortC and pin number as output
      
    }
    else{
      ClearBit(PORTC,Pin); //Clear PortC and Pin number       
      
    }
    break;
        case 'D':
    if (Direction == 1)
    {
      SetBit(PORTD,Pin);//Setting PortD and pin number as output  
      
    }
    else{
      ClearBit(PORTD,Pin); //Clear PortD and Pin number      
      
    }
    break;
}
}