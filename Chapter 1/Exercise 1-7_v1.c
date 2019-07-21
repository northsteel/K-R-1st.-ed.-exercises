/* Copies input to output, replacing each string of one or 
more blanks by a single blank */

#include <stdio.h>

int main()
{
    int numOutBlanks, charCode;
    
    while((charCode = getchar()) != EOF)
    {
        if (charCode == ' ')
        {
            if (numOutBlanks < 1)
                putchar(charCode);
            
            ++numOutBlanks;
        }
        else
        {
            putchar(charCode);
            
            numOutBlanks = 0;
        }
    }
}