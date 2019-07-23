// Exercise 1-12. Write a program to print a histogram of the lengths of words
// in its input. It is easiest to draw the histogram horizontally; a vertical 
// orientation is more challenging.

// Definition of the word can be found in the solution to exercise 1-11

#include <stdio.h>

#define YES 1
#define NO 0
#define MAX_WORD_LENGTH 50

int main()
{
	int charCode, index, prevCharCode, inWord, wordLength;

	// This var stores the previous character in the stream.
	prevCharCode = '\n';

	inWord = NO;

	wordLength = 0;

	// This array will contain the number of words that have a length equal to the index of the array + 1
	// For example array[0] will store the number of words that has a length of one, i. e., 0 + 1.
	
	int numChar[MAX_WORD_LENGTH];

	// Initializeing the array of the length of words.
	for (index = 0; index < MAX_WORD_LENGTH; ++index)
	{
		numChar[index] = 0;
	}

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
				
				++numChar[wordLength - 1];
				wordLength = 0;
			}
		}
		else if (charCode >= 'A' && charCode <= 'Z' || charCode >= 'a' && charCode <= 'z')
		{
			if (prevCharCode == ' ' || prevCharCode == '\n' || prevCharCode == '\t')
			{
				inWord = YES;
			}
		}
		
		if (inWord == YES)
			++wordLength;
		
		prevCharCode = charCode;
	}
	
	// Count last word if any
	if (inWord == YES)
		++numChar[wordLength - 1];

/*
	// Do this while there are characters in a stream.
	while ((charCode = getchar()) != EOF)
	{
		// Check if character is an English letter.
		if (charCode >= 'A' && charCode <= 'Z' || charCode >= 'a' && charCode <= 'z')
		{
			// This character is an English letter.

			// Is it not inside a possible word?
			if (prevChar == ' ' || prevChar == '\n' || prevChar == '\t')
			{
				// Possible word.
				inword = YES;

				wordLength = 1;
			}

			if (inword == YES)
			{
				++wordLength;
			}
		}
		// Maybe it is a digit 0-9?
		else if (charCode >= '0' && charCode <= '9')
		{
			// It is a digit character.
			if (inword == YES)
			{
				++wordLength;
			}
		}
		// Maybe it is the apostrophe?
		else if (charCode == '\'')
		{
			// It is the apostrophe.
			if (inword == YES)
			{
				++wordLength;
			}
		}
		// Is it a new line, blank or a tab?
		else if (charCode == ' ' || charCode == '\n' || charCode == '\t')
		{
			// It is a new line or blank or tab.

			// Were the previous characters in word?
			if (inword == YES)
			{
				lastIndex = wordLength - 1;

				++numChar[lastIndex];

				inword = NO;
			}
		}
		// All other characters
		else
		{
			inword = NO;
		}

		prevChar = charCode;
	}
*/

	// Draw horizontal histogram.
	printf("Word lengths = \n");
	
	// Find the index of last element that is > 0,
	// in other words, the element that stores the frequency
	// of max length word
	int lastIndex = MAX_WORD_LENGTH - 1;
	for (index = MAX_WORD_LENGTH - 1; index >= 0; --index)
		if (numChar[index] > 0)
		{
			lastIndex = index;
			
			break;
		}
	
	for (index = 0; index <= lastIndex; ++index)
	{
		printf("%2d:", index + 1);

		for (int j = 0; j < numChar[index]; ++j)
		{
			printf(" %c", '*');
		}

		printf("\n");
	}
}
