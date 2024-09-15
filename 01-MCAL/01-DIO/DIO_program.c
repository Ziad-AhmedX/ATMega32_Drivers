/**
 * @file DIO_program.c
 * @brief Source file for the DIO (GPIO) driver.
 * 
 * @author ZIAD AHMED
 * @LAYER MCAL
 * @SWC DIO/GPIO
 * 
 * This file contains the implementation of the DIO driver for managing GPIO pins 
 * in a microcontroller.
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/**
 * @brief Sets the direction of a specific pin (INPUT or OUTPUT).
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7).
 * @param Copy_u8Direction Pin direction (DIO_PIN_OUTPUT, DIO_PIN_INPUT).
 * @return DIO_ErrorStatus Status of the operation.
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

/**
 * @brief Sets the value of a specific pin (HIGH or LOW).
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7).
 * @param Copy_u8Value Pin value (DIO_PIN_LOW, DIO_PIN_HIGH).
 * @return DIO_ErrorStatus Status of the operation.
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

/**
 * @brief Gets the value of a specific pin (HIGH or LOW).
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7).
 * @param Copy_u8PtrData Pointer to store the pin value.
 * @return DIO_ErrorStatus Status of the operation.
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

/**
 * @brief Toggles the value of a specific pin.
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7).
 * @return DIO_ErrorStatus Status of the operation.
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


/**
 * @brief Sets the direction of the entire port (INPUT or OUTPUT).
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8Direction Port direction (DIO_PIN_OUTPUT, DIO_PIN_INPUT).
 * @return DIO_ErrorStatus Status of the operation.
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

/**
 * @brief Sets the value of the entire port (HIGH or LOW).
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8Value Port value (DIO_PORT_HIGH, DIO_PORT_LOW).
 * @return DIO_ErrorStatus Status of the operation.
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

/**
 * @brief Gets the value of the entire port.
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param Copy_u8PtrData Pointer to store the port value.
 * @return DIO_ErrorStatus Status of the operation.
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
/**
 * @brief Toggles the value of the entire port.
 * 
 * @param Copy_u8PORT Port name (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 */
DIO_ErrorStatus DIO_enumTogglePortValue (u8 Copy_u8PORT )
{
		DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8PORT <= DIO_PORTD )
	{
	switch(Copy_u8PORT)
	{
		   case DIO_PORTA  :TOG_PORT(PORTA);break;
		   case DIO_PORTB  :TOG_PORT(PORTB);break;
		   case DIO_PORTC  :TOG_PORT(PORTC);break;
		   case DIO_PORTD  :TOG_PORT(PORTD);break;
	}
	}
	else 
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
