/* Exercise 1-19. Write a program detab which replaces tabs in the input
with the proper number of blanks to space to the next tab stop. Assume a
fixed set of tab stops, say every n positions */

#include <stdio.h>

#define TAB_SIZE 4

int main()
{
	int charCode;
	int numBlanksToPlace = TAB_SIZE;
	
	while ( (charCode = getchar()) != EOF)
		if (charCode == '\t')
			for ( int idx = numBlanksToPlace; idx > 0; --idx)
			{
				putchar(' ');
				
				if (numBlanksToPlace == 1)
					numBlanksToPlace = 4;
				else
					--numBlanksToPlace;
			}
		else
		{
			putchar(charCode);
			
			if (numBlanksToPlace == 1 || charCode == '\n')
				numBlanksToPlace = 4;
			else
				--numBlanksToPlace;
		}
}
