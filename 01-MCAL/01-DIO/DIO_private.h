/**
 * @file DIO_private.h
 * @brief Private definitions and register addresses for the DIO (GPIO) driver.
 * 
 * This file contains the definitions for the DIO registers, which are used to control
 * and manage the General-Purpose Input/Output (GPIO) pins of the microcontroller.
 * 
 * @author ZIAD AHMED
 * @layer MCAL
 * @swc DIO/GPIO
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/** 
 * @brief PORTA Register
 * 
 * The PORTA register controls the output levels of the pins on PORTA when the pins are configured as OUTPUT.
 * When the pins are configured as INPUT, writing to this register can enable the internal pull-up resistors.
 */
#define PORTA *((volatile u8*) 0x3B)

/** 
 * @brief DDR (Data Direction Register) for PORTA
 * 
 * The DDRA register sets the direction (INPUT/OUTPUT) for the pins on PORTA.
 */
#define DDRA *((volatile u8*) 0x3A)

/** 
 * @brief PIN (Pin Input Register) for PORTA
 * 
 * The PINA register reads the input values of the pins on PORTA.
 */
#define PINA *((volatile u8*)0x39)

/** 
 * @brief PORTB Register
 * 
 * The PORTB register controls the output levels of the pins on PORTB when the pins are configured as OUTPUT.
 * When the pins are configured as INPUT, writing to this register can enable the internal pull-up resistors.
 */
#define PORTB *((volatile u8*) 0x38)

/** 
 * @brief DDR (Data Direction Register) for PORTB
 * 
 * The DDRB register sets the direction (INPUT/OUTPUT) for the pins on PORTB.
 */
#define DDRB *((volatile u8*)0x37)

/** 
 * @brief PIN (Pin Input Register) for PORTB
 * 
 * The PINB register reads the input values of the pins on PORTB.
 */
#define PINB *((volatile u8*)0x36)

/** 
 * @brief PORTC Register
 * 
 * The PORTC register controls the output levels of the pins on PORTC when the pins are configured as OUTPUT.
 * When the pins are configured as INPUT, writing to this register can enable the internal pull-up resistors.
 */
#define PORTC *((volatile u8*)0x35)

/** 
 * @brief DDR (Data Direction Register) for PORTC
 * 
 * The DDRC register sets the direction (INPUT/OUTPUT) for the pins on PORTC.
 */
#define DDRC *((volatile u8*)0x34)

/** 
 * @brief PIN (Pin Input Register) for PORTC
 * 
 * The PINC register reads the input values of the pins on PORTC.
 */
#define PINC *((volatile u8*)0x33)

/** 
 * @brief PORTD Register
 * 
 * The PORTD register controls the output levels of the pins on PORTD when the pins are configured as OUTPUT.
 * When the pins are configured as INPUT, writing to this register can enable the internal pull-up resistors.
 */
#define PORTD *((volatile u8*) 0x32)

/** 
 * @brief DDR (Data Direction Register) for PORTD
 * 
 * The DDRD register sets the direction (INPUT/OUTPUT) for the pins on PORTD.
 */
#define DDRD *((volatile u8*) 0x31)

/** 
 * @brief PIN (Pin Input Register) for PORTD
 * 
 * The PIND register reads the input values of the pins on PORTD.
 */
#define PIND *((volatile u8*)0x30)

#endif /* DIO_PRIVATE_H_ */

