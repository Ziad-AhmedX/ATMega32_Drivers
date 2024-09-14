/*
*<<<<<<<<<<<<<<<<<<<<<<< DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>*
*
* AUTHOR : ZIAD AHMED
* LAYER : MCAL
* SWC : DIO/GPIO
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                      IO PINS                  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function sets the direction of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  => Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  => Copy_u8Direction --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * Return : its status
 */
DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD && Copy_u8PIN <= DIO_PIN7)
	{
		if (Copy_u8Direction == DIO_PIN_OUTPUT) {
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: SET_BIT(DDRA, Copy_u8PIN); break;
				case DIO_PORTB: SET_BIT(DDRB, Copy_u8PIN); break;
				case DIO_PORTC: SET_BIT(DDRC, Copy_u8PIN); break;
				case DIO_PORTD: SET_BIT(DDRD, Copy_u8PIN); break;
			}
		}
		else if (Copy_u8Direction == DIO_PIN_INPUT)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: CLR_BIT(DDRA, Copy_u8PIN); break;
				case DIO_PORTB: CLR_BIT(DDRB, Copy_u8PIN); break;
				case DIO_PORTC: CLR_BIT(DDRC, Copy_u8PIN); break;
				case DIO_PORTD: CLR_BIT(DDRD, Copy_u8PIN); break;
			}
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function sets the Value of the Pin  (HIGH || LOW)
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  => Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  => Copy_u8Value --> Pin Value [ DIO_PIN_LOW , DIO_PIN_HIGH ]
 * Return : its status
 */
DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD && Copy_u8PIN <= DIO_PIN7)
	{
		if (Copy_u8Value == DIO_PIN_HIGH) {
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: SET_BIT(PORTA, Copy_u8PIN); break;
				case DIO_PORTB: SET_BIT(PORTB, Copy_u8PIN); break;
				case DIO_PORTC: SET_BIT(PORTC, Copy_u8PIN); break;
				case DIO_PORTD: SET_BIT(PORTD, Copy_u8PIN); break;
			}
		}
		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: CLR_BIT(PORTA, Copy_u8PIN); break;
				case DIO_PORTB: CLR_BIT(PORTB, Copy_u8PIN); break;
				case DIO_PORTC: CLR_BIT(PORTC, Copy_u8PIN); break;
				case DIO_PORTD: CLR_BIT(PORTD, Copy_u8PIN); break;
			}
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK; 
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function gets the Pin Value (HIGH || LOW)
 * Parameters : 
        => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTC ]
		=> Copy_u8PIN --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ] 
		=> *Copy_u8PtrData --> Pointer To Receive The Pin Value
 * Return : Its Status and Receive Pin Value In Pointer		
 */
DIO_ErrorStatus DIO_enumGetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8* Copy_u8PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD && Copy_u8PIN <= DIO_PIN7)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA: *Copy_u8PtrData = GET_BIT(PINA, Copy_u8PIN); break;
			case DIO_PORTB: *Copy_u8PtrData = GET_BIT(PINB, Copy_u8PIN); break;
			case DIO_PORTC: *Copy_u8PtrData = GET_BIT(PINC, Copy_u8PIN); break;
			case DIO_PORTD: *Copy_u8PtrData = GET_BIT(PIND, Copy_u8PIN); break;
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function Toggles the Value of the Pin  
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  => Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * Return : its status
 */
DIO_ErrorStatus DIO_enumTogglePinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD && Copy_u8PIN <= DIO_PIN7)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: TOG_BIT(PORTA, Copy_u8PIN); break;
			case DIO_PORTB: TOG_BIT(PORTB, Copy_u8PIN); break;
			case DIO_PORTC: TOG_BIT(PORTC, Copy_u8PIN); break;
			case DIO_PORTD: TOG_BIT(PORTD, Copy_u8PIN); break;
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                          IO PORTS                     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function sets the direction of the Port  (INPUT || OUTPUT)
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  => Copy_u8Direction --> Port Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * Return : its status
 */
DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD)  
	{
		if (Copy_u8Direction == DIO_PIN_OUTPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA: SET_PORT(DDRA); break;
				case DIO_PORTB: SET_PORT(DDRB); break;
				case DIO_PORTC: SET_PORT(DDRC); break;
				case DIO_PORTD: SET_PORT(DDRD); break;
			}
		}
		else if (Copy_u8Direction == DIO_PIN_INPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA: CLR_PORT(DDRA); break;
				case DIO_PORTB: CLR_PORT(DDRB); break;
				case DIO_PORTC: CLR_PORT(DDRC); break;
				case DIO_PORTD: CLR_PORT(DDRD); break;
			}
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function sets the Value of the Port (HIGH || LOW)
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  => Copy_u8Value --> Port Value [ DIO_PORT_HIGH , DIO_PORT_LOW ]
 * Return : its status
 */
DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD)
	{
		if (Copy_u8Value == DIO_PORT_HIGH)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA: SET_PORT(PORTA); break;
				case DIO_PORTB: SET_PORT(PORTB); break;
				case DIO_PORTC: SET_PORT(PORTC); break;
				case DIO_PORTD: SET_PORT(PORTD); break;
			}
		}
		else if (Copy_u8Value == DIO_PORT_LOW)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA: CLR_PORT(PORTA); break;
				case DIO_PORTB: CLR_PORT(PORTB); break;
				case DIO_PORTC: CLR_PORT(PORTC); break;
				case DIO_PORTD: CLR_PORT(PORTD); break;
			}
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function gets the Value of the Port  (HIGH || LOW)
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  => Copy_u8PtrData--> Pointer To Receive The Port Value
 * Return : its status And Receive Port Value In Pointer
 */
DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8PORT, u8* Copy_u8PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: *Copy_u8PtrData = GET_PORT(PINA); break;
			case DIO_PORTB: *Copy_u8PtrData = GET_PORT(PINB); break;
			case DIO_PORTC: *Copy_u8PtrData = GET_PORT(PINC); break;
			case DIO_PORTD: *Copy_u8PtrData = GET_PORT(PIND); break;
		}
	}
	else 
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function Toggles the Value of the Port
 * Parameters :
  	  => Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * Return : its status
 */
void DIO_voidTogglePortValue(u8 Copy_u8PORT)
{
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: TOG_PORT(PORTA); break;
			case DIO_PORTB: TOG_PORT(PORTB); break;
			case DIO_PORTC: TOG_PORT(PORTC); break;
			case DIO_PORTD: TOG_PORT(PORTD); break;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------


























