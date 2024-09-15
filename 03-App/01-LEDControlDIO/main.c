/**
 * @file main.c
 * @brief Main application file for controlling GPIO ports.
 * 
 * Initializes GPIO ports and toggles their states with a delay.
 * 
 * @author ZIAD AHMED
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/**
 * @brief Introduces a delay in milliseconds.
 * 
 * Creates a delay by executing nested loops. The duration of the delay is
 * approximately proportional to the `counter` parameter.
 * 
 * @param counter Delay duration in milliseconds.
 */
void custom_delay_ms(u32 counter); 

/**
 * @brief Main function to control GPIO ports.
 * 
 * Initializes PORTA and PORTD as output and alternates their states in an infinite loop.
 * 
 * @return int Does not return a value.
 */
int main()
{
    // Set PORTA and PORTD as output ports
    DIO_enumSetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);  
    DIO_enumSetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);  

    while (1)
    { 
        // Set PORTA high and PORTD low
        DIO_enumSetPortValue(DIO_PORTA, DIO_PORT_HIGH);
        DIO_enumSetPortValue(DIO_PORTD, DIO_PORT_LOW);
        
        // Introduce delay
        custom_delay_ms(1);
        
        // Set PORTA low and PORTD high
        DIO_enumSetPortValue(DIO_PORTA, DIO_PORT_LOW);
        DIO_enumSetPortValue(DIO_PORTD, DIO_PORT_HIGH);
        
        // Introduce delay
        custom_delay_ms(1);
    }
}



void custom_delay_ms(u32 counter)
{
    int i = 0, j = 0;
    counter *= 1500; 
    for (; i < counter; i++) // Main loop 
        for (; j < 25500; j++)   // Nested loop 
            asm volatile("nop");   // NOP instruction
}

