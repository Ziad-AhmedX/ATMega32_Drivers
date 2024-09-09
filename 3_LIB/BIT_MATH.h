/*
 *<<<<<<<<<<<<<<<<<<<<<<< DIO_MATH.h >>>>>>>>>>>>>>>>>>>>>>>>*
 *
 * AUTHOR : ZIAD AHMED
 * LAYER : LIB
 *
 *
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define REGISTER_SIZE 8                                     // ATMEGA32 8bit
#define REG_RANGE(reg_bit_num)  ((1 << (reg_bit_num )) -1)  // Maximum value representable 


                             /*PIN*/

#define SET_BIT(reg, bit) reg |= (1 << bit)
#define CLR_BIT(reg, bit) reg &= (~(1 << bit))
#define TOG_BIT(reg, bit) reg ^= (1 << bit)
#define GET_BIT(reg, bit) (reg & (1 << bit)) >> bit  // ((reg >> bit)&1) --> &1 == |0

#define IS_BIT_SET(reg, bit) ((reg >> bit) & 1)     // 1 --> true .. 0 --> false
#define IS_BIT_CLR(reg, bit) !((reg >> bit) & 1)    // if clear --> true (1) ,... not clear --> false (0)                 
#define ROR(reg, num) reg = ((reg >> num) | (reg << (REGISTER_SIZE - num)))
#define ROL(reg, num) reg = ((reg << num) | (reg >> (REGISTER_SIZE - num)))

                            /*PORT*/
							
#define SET_PORT(reg) reg |= REG_RANGE(REGISTER_SIZE) 
#define CLR_PORT(reg) reg &= (~(REG_RANGE(REGISTER_SIZE)))
#define TOG_PORT(reg) reg ^= REG_RANGE(REGISTER_SIZE)      
#define GET_PORT(reg) (reg & (REG_RANGE(REGISTER_SIZE)))   // Another Solution --> reg |= 0 
							

#endif /*BIT_MATH_H_*/
