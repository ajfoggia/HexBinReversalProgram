#include <stdio.h>
#include "Num_Choice.h"  //Inclusion of the header file for compile selections and macros

int main()
{

    unsigned int rev_temp = 0;  //Temporary variable used for holding the reversed number
    unsigned int undo_rev_temp = 0;  //Temporary variable used for holding the second reversal
    int definedNumber;  //Variable that holds the number being manipulated (changes based on compile time selection)

#if ONE  //First number is chosen at compile time
    definedNumber = HEX;  //The value of HEX is then manipulated
#endif

#if TWO  //Second number is chosen at compile time
    definedNumber = NEG_INT;  //The value of NEG_INT is then manipulated
#endif

#if THREE  //Third number is chosen at compile time
    definedNumber = POS_INT;  //The value of POS_INT is then manipulated
#endif

#if BIN  //Output is to be in binary based on the compile time selection

    printf("The original binary number is:          ");
    for(int i = B_Size, temp = 0; i > 0;)  //Loop to display the original number
    {
        --i;
        temp = EXTRACT(definedNumber, i, BIT);
        rev_temp |= INSERT(temp, i);
        printf("%d",temp);
    }
    printf("\n\n");

    printf("After the first reverse the number is:  ");
    for(int i = 0, temp = 0; i < B_Size; i++)  //Loop that performs/displays the first reverse
    {
        temp = EXTRACT(definedNumber, i, BIT);
        rev_temp |= INSERT(temp, i);
        printf("%d",temp);
    }
    printf("\n\n");

    printf("After the second reverse the number is: ");
    for(int i = 0, temp = 0; i < B_Size; i++)  //Loop that performs/displays the second reverse (original number)
    {
        temp = EXTRACT(rev_temp, i, BIT);
        undo_rev_temp |= INSERT(temp, i);
        printf("%d",temp);
    }
    printf("\n\n");

#else  //The compile selection for output is hex

    printf("The original number in hex is:          0x%08X", definedNumber);
    rev_temp = 0;  //Re-initialize rev_temp
    undo_rev_temp = 0;  //Re-initialize undo_rev_temp

    for(int i = BIT_Pull, temp = 0; i < B_Size;)  //Loop that performs/displays the first reverse
    {
        temp = EXTRACT(definedNumber, i, NIBBLE);
        rev_temp |= INSERT(temp, i);
        i += NIBBLE;
    }

    printf("\nAfter the first reverse the number is:  0x%08X", rev_temp);

    for(int i = BIT_Pull, temp = 0; i < B_Size;)  //Loop that performs/displays the second reverse (original number)
    {
        temp = EXTRACT(rev_temp, i, NIBBLE);
        undo_rev_temp |= INSERT(temp, i);
        i += NIBBLE;
    }

    printf("\nAfter the second reverse the number is: 0x%08X\n", undo_rev_temp);

#endif

    return 0;
}