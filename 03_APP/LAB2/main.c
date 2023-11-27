/******************************************************************
					Author  : Shirehan Medhat Abdeldsalam Ali
					Date    : 26-1-2023
					Driver  : DIO
					File    : main.c
					Version : (1)
*****************************************************************/
///**************************** DELETE HERE TO UNCOMMENT THE CODE
#include "../../01_MCAL/00_DIO/DIO.h"
#define F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
	 u8 read = HIGH , counter =0;
	 DIO_enumError_t  mainErrorState = NOK ;
	//Replace with your application code 
	//Set PA0, PA1 , PA2 , PA3 as outputs
	DIO_enumSetPinConfig (PORTA_Choice , PIN0 , OUTPUT);
	DIO_enumSetPinConfig (PORTA_Choice , PIN1 , OUTPUT);
	DIO_enumSetPinConfig (PORTA_Choice , PIN2 , OUTPUT);
	DIO_enumSetPinConfig (PORTA_Choice , PIN3 , OUTPUT);
	//Set PB1 as an input PullUp
	DIO_enumSetPinConfig (PORTB_Choice , PIN1  , INPUT_PULLUP);
		while (1)
		{
			  mainErrorState = DIO_enumReadState (PORTB_Choice , PIN1 , &read);

			//READ the switch
			if (mainErrorState == OK )
			{
				
				if (!read)
				{
					//Delay to hang the cpu for 250 ms
					_delay_ms(250);
					//reread to check if it's a real press
					if (!read)
					{
						//Start Over at count =15
						if (counter==16) counter=0;
						counter++;
						//Show the Result on LEDs
						DIO_enumSetPort (PORTA_Choice , counter);
						
						
					}
					else
					{
						//Do Nothing
					}
				}
				else
				{
					//Do Nothing
				}
				
			}
			else
			{
				//Do Nothing
			}
			
		}
	}

//TO HERE ********************************/

