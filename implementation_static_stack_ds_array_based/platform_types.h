/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 13/7/2023
 * @brief  : it contains the standard types for gcc compilor
 **************************************************************
*/


#ifndef _PLATFORM_TYPES_
#define _PLATFORM_TYPES_
#define ZERO 0
// types for gcc compilor
// define types
typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char  sint8_t;
typedef signed short sint16_t;
typedef signed int   sint32_t;
typedef float float32;
typedef double float64;

// ok or not ok
typedef enum 
{
    return_nok=0,
    return_ok,
}return_state_t;


#endif