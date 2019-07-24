/* Exercise 1-13. Write a program to convert its input to lower case, 
using a function lower(c) which returns c if c is not a letter, and the 
lower case value of c if it is a letter. */

#include <stdio.h>

#define ASCII_LOWERCASE_OFFSET 32

int lower(int charCode)
{
	if (charCode >= 'A' && charCode <= 'Z')
		return (charCode + ASCII_LOWERCASE_OFFSET);
	else
		return charCode;
}

int main()
{
	int charCode;
	
	while((charCode = getchar()) != EOF)
	{
		putchar(lower(charCode));
	}
}
