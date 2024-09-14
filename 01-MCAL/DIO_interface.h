/**
 * @file DIO_interface.h
 * @brief Interface definitions and function prototypes for the DIO (GPIO) driver.
 * 
 * This file contains the public interface for the DIO (GPIO) driver, including 
 * macro definitions and function prototypes for controlling and managing GPIO pins 
 * and ports.
 * 
 * @author ZIAD AHMED
 * @layer MCAL
 * @swc DIO/GPIO
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/** 
 * @brief Pin direction values
 */
#define DIO_PIN_OUTPUT 1  /**< Pin direction is OUTPUT */
#define DIO_PIN_INPUT 0   /**< Pin direction is INPUT */

/** 
 * @brief Pin value states
 */
#define DIO_PIN_HIGH 1    /**< Pin value is HIGH */
#define DIO_PIN_LOW 0     /**< Pin value is LOW */

/** 
 * @brief Ports
 */
#define DIO_PORTA 0       /**< PORTA */
#define DIO_PORTB 1       /**< PORTB */
#define DIO_PORTC 2       /**< PORTC */
#define DIO_PORTD 3       /**< PORTD */

/** 
 * @brief Pin numbers
 */
#define DIO_PIN0 0        /**< Pin 0 */
#define DIO_PIN1 1        /**< Pin 1 */
#define DIO_PIN2 2        /**< Pin 2 */
#define DIO_PIN3 3        /**< Pin 3 */
#define DIO_PIN4 4        /**< Pin 4 */
#define DIO_PIN5 5        /**< Pin 5 */
#define DIO_PIN6 6        /**< Pin 6 */
#define DIO_PIN7 7        /**< Pin 7 */

/** 
 * @brief Port direction values
 */
#define DIO_PORT_OUTPUT 1 /**< Port direction is OUTPUT */
#define DIO_PORT_INPUT 0  /**< Port direction is INPUT */

/** 
 * @brief Port value states
 */
#define DIO_PORT_HIGH 1   /**< Port value is HIGH */
#define DIO_PORT_LOW 0    /**< Port value is LOW */

/** 
 * @brief Error status enumeration for DIO operations
 */
typedef enum {
    DIO_NOK, /**< Operation Failed */
    DIO_OK   /**< Operation Success */
} DIO_ErrorStatus;

/** 
 * @brief Set the direction of a specific pin
 * 
 * @param copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7)
 * @param copy_u8DIRECTION Direction (DIO_PIN_INPUT or DIO_PIN_OUTPUT)
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8DIRECTION);

/** 
 * @brief Set the value of a specific pin
 * 
 * @param copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7)
 * @param copy_u8VALUE Value (DIO_PIN_LOW or DIO_PIN_HIGH)
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE);

/** 
 * @brief Get the value of a specific pin
 * 
 * @param copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7)
 * @param Copy_u8PtrData Pointer to store the pin value
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumGetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 *Copy_u8PtrData);

/** 
 * @brief Toggle the value of a specific pin
 * 
 * @param Copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param Copy_u8PIN Pin number (DIO_PIN0 to DIO_PIN7)
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumTogglePinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

/** 
 * @brief Set the direction of all pins on a port
 * 
 * @param Copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param Copy_u8Direction Direction (DIO_PORT_INPUT or DIO_PORT_OUTPUT)
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction);

/** 
 * @brief Set the value of all pins on a port
 * 
 * @param Copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param Copy_u8Value Value (DIO_PORT_LOW or DIO_PORT_HIGH)
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value);

/** 
 * @brief Get the value of all pins on a port
 * 
 * @param Copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * @param Copy_u8PtrData Pointer to store the port value
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8PORT, u8* Copy_u8PtrData);

/** 
 * @brief Toggle the value of all pins on a port
 * 
 * @param Copy_u8PORT Port number (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 * 
 * @return DIO_ErrorStatus Status of the operation
 */
DIO_ErrorStatus DIO_enumTogglePortValue(u8 Copy_u8PORT);

#endif /* DIO_INTERFACE_H_ */

