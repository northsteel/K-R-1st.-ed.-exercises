/* Copies input to output, replacing each string of one or 
more blanks by a single blank */

#include <stdio.h>

int main()
{
    int c, prevChar;
    prevChar = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (!(prevChar == ' ' & c == ' '))
        {
            putchar(c);
        }
    
        prevChar = c;
    }
}