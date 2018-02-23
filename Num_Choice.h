//
// Created by ajfoggia on 1/30/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef REV_PROGRAM_NUM_CHOICE_H
#define REV_PROGRAM_NUM_CHOICE_H
#define B_Size 32  //Macro that holds the binary size constant at 32
#define BIN_MANIP_SIZE 31  //Macro that holds the size of the binary number when manipulated

#ifdef BIN  //Compile choice for binary output
#define BIT 1  //Constant that holds the size of a bit
#define BIT_MASK ~(~0 << BIT)  //Macro that creates bit mask for binary case
#else  //If compile choice is not binary output, the choice is hex
#define NIBBLE 4  //Macro that holds the size of a nibble (4 bits)
#define BIT_MASK ~(~0 << NIBBLE)  //Macro that creates bit mask for hex case
#define BIT_Pull 3  //Macro used to pull bits 0-3 for hex numbers
#endif

#ifdef ONE  //Compile choice is the first number: 0x13579BDF
#define HEX 0x13579BDF  //Macro that holds the value of the hex number
#endif

#ifdef TWO  //Compile choice is the second number: -65536
#define NEG_INT -65536  //Macro that holds the value for the negative integer
#endif

#ifdef THREE  //Compile choice is the third number: 100
#define POS_INT 100  //Macro that holds the value for the positive integer
#endif

#define EXTRACT(digits, placement, n_bits) ((digits >> ((placement + 1) - n_bits)) & BIT_MASK)  //Macro that performs the extraction
#define INSERT(digits, bits) (digits << BIN_MANIP_SIZE - bits)  //Macro that performs the insertion


#endif //REV_PROGRAM_NUM_CHOICE_H