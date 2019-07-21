/* Prints the words in its input, one per line */

#include <stdio.h>

#define YES 1
#define NO 0

int main()
{
	int charCode, inWord;	

	inWord = NO;
	while((charCode = getchar()) != EOF)
	{
		if (charCode == ' ' || charCode == '\n' || charCode == '\t')
		{
			if (inWord == YES)
			{
				putchar('\n');
			
				inWord = NO;
			}
		}
		else
		{
			putchar(charCode);
			
			if (inWord == NO)
				inWord = YES;
		}
	}
}