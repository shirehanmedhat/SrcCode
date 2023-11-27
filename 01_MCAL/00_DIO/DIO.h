/******************************************************************
					Author  : Shirehan Medhat Abdeldsalam Ali
					Date    : 26-1-2023
					Driver  : DIO
					File    : DIO.h
					Version : (1)
*****************************************************************/

#include "../../00_LIB/Bitmath.h"
#include "../../00_LIB/STD_Types.h"

#ifndef DIO_H_
#define DIO_H_

#define DDRA          *((volatile u8*)0x3A)
#define PORTA         *((volatile u8*)0x3B)
#define PINA          *((volatile u8*)0x39)

#define DDRB          *((volatile u8*)0x37)
#define PORTB         *((volatile u8*)0x38)
#define PINB         *((volatile u8*)0x36)

#define DDRC          *((volatile u8*)0x34)
#define PORTC         *((volatile u8*)0x35)
#define PINC          *((volatile u8*)0x33)

#define DDRD          *((volatile u8*)0x31)
#define PORTD         *((volatile u8*)0x32)
#define PIND         *((volatile u8*)0x30)


/*Enum for the returned error state*/
typedef enum {NOK,OK} DIO_enumError_t;

/*Enum for the choices of ports*/
typedef enum 
{PORTA_Choice , PORTB_Choice , PORTC_Choice ,PORTD_Choice}DIO_enumPorts_t;
/*Enum to represent the pins for each port*/
typedef enum {PIN0 , PIN1 , PIN2 , PIN3 , PIN4 , PIN5 , PIN6 , PIN7}DIO_enumPins_t;
/*Enum to configure the direction */	
typedef enum {OUTPUT, INPUT_PULLUP , INPUT_PULLDOWN}DIO_enumConfig_t;
/*Enum to represent the high and low representation*/	
typedef enum {LOW , HIGH}DIO_enumLogicState_t;
	
/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue);



DIO_enumError_t DIO_enumReadPortState(DIO_enumPorts_t Copy_enumPortNum , u8* Add_Pu8PortValue);




#endif /* DIO_H_ */