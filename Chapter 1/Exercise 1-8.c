/* Replaces each tab by the three-character sequence
>, backspace, -, which prints as ->, and each backspace by
similar sequence <- */

#include <stdio.h>

int main()
{
    int charCode;

    while ((charCode = getchar()) != EOF)
	{
		if (charCode == '\t')
		{
			putchar('-');
			putchar('>');
		}
		else if (charCode == '\b')
		{
			putchar('<');
			putchar('-');
		}
		else
			putchar(charCode);
	}
}