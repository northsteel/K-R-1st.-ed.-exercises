// Exercise 1-11
// Word is a sequence of letters a-z or A-Z, digits 0-9 and apostrophes (')
// that begins with a letter a-z or A-Z.

#include <iostream>

#define YES 1
#define NO 0

int main()
{
	int c, prevChar, nl, nw, nc, inword;

	inword = NO;
	nl = nw = nc = 0;

	prevChar = '\n';
	while ((c = getchar()) != EOF)
	{
		// Count characters
		++nc;

		if (c == '\n')
		{
			// Count new line characters.
			++nl;
		}

		// Check if character is an English letter.
		if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
		{
			// This character is an English letter.

			// Is it not inside a possible word?
			if (prevChar == ' ' || prevChar == '\n' || prevChar == '\t')
			{
				// Possible word.
				inword = YES;
			}
		}
		// Maybe it is a digit 0-9?
		else if (c >= 48 && c <= 57)
		{
			// It is a digit character.
		}
		// Maybe it is the apostrophe?
		else if (c == 39)
		{
			// It is the apostrophe.
		}
		// Is it a new line, blank or a tab?
		else if (c == ' ' || c == '\n' || c == '\t')
		{
			// It is a new line or blank or tab.

			// Were the previous characters in word?
			if (inword == YES)
			{
				// It was a word, increment word counter.
				++nw;

				inword = NO;
			}
		}
		// All other characters
		else
		{
			inword = NO;
		}

		prevChar = c;
	}

	printf("Lines: %d, words: %d, chars: %d\n", nl, nw, nc);

	return 0;
}