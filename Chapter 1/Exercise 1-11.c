// Exercise 1-11. Revise the word count program to use a better definition of
// "word," for example, a sequence of letters, digits and apostrophes that
// begins with a letter.

// Word is a sequence of letters a-z or A-Z that begins with a letter a-z or A-Z
// Words are seperated by a blank, a newline or a tab

// Examples:
// "3some" is not a word
// "n1" is not a word
// "444" is not a word
// "some" is a word
// "sOmE" is a word
// "NASA" is a word
// "(blank" is a word
// "end.", "course," are words
// "don't" is a word

#include <stdio.h>

#define YES 1
#define NO 0

int main()
{
	int charCode, prevCharCode, numWords, inWord;

	inWord = NO;
	numWords= 0;

	// Set the previous character to be a new line character.
	prevCharCode = '\n';

	// Do this while getchar does not return EOF.
	while ((charCode = getchar()) != EOF)
	{
		if (charCode >=  '0' && charCode <= '9')
		{
			inWord = NO;
		}
		else if (charCode == ' ' || charCode == '\n' || charCode == '\t')
		{
			if (inWord == YES)
			{
				inWord = NO;
				++numWords;
			}
		}
		else if (charCode >= 'A' && charCode <= 'Z' || charCode >= 'a' && charCode <= 'z')
		{
			if (prevCharCode == ' ' || prevCharCode == '\n' || prevCharCode == '\t')
			{
				inWord = YES;
			}
		}
		
		prevCharCode = charCode;
	}
	
	// Count last word if any
	if (inWord == YES)
		++numWords;

	printf("Number of words: %d\n", numWords);
}
