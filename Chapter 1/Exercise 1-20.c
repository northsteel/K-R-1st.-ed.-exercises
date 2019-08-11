/* Exercise 1-20. Write the program entab which replaces strings of 
blanks by the minimum number of tabs and blanks to achieve the same 
spacing. Use the same tab stops as for detab. */

#include <stdio.h>

#define TAB_SIZE 4

int main()
{
	int charCode;
	int numBlanks = 0;
	int pos = 0;
	
	while ( (charCode = getchar()) != EOF)
	{
		if (charCode == ' ')
		{
			if ( pos == 0 )
			{
				++numBlanks;
				
				if (numBlanks == TAB_SIZE)
				{
					putchar('\t');
					numBlanks = 0;
					pos = 0;
				}
			}
			else
			{
				putchar(' ');
				
				if ( pos == (TAB_SIZE - 1) )
					pos = 0;
				else
					++pos;
			}
		}
		else
		{
			while (numBlanks > 0)
			{
				putchar(' ');
				--numBlanks;
				++pos;
			}
			
			putchar(charCode);
			
			if ( pos == (TAB_SIZE - 1) || charCode == '\n')
				pos = 0;
			else
				++pos;
		}
	}
	
	// Output remaining spaces
	while (numBlanks > 0)
	{
		putchar(' ');
		--numBlanks;
	}
}
