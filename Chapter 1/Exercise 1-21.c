/* Exercise 1-21. Write a program to "fold" long input lines after the 
last non-blank character that occurs before the n-th column of input,
where n is a parameter. Make sure your program does something intelligent
with very long lines, and if there are no blanks or tabs before the 
specified column */

/* Program breaks the input into seperate lines based on the number of 
characters in the input. For example, if the next character after fold
column is a tab character that will not be printed, it still counts asctime
TAB_SIZE characters long. */

#include <stdio.h>

#define MAXLINE 1000 /* Maximum input line size */
#define TAB_SIZE 4
#define YES 1
#define NO 0

int main()
{
	// This array will store characters until we reach the fold column or
	// the limit, or until encounter a newline character.
	char line[MAXLINE];
	
	// This is a fold column number, character at this column and after that
	// will be printed on next lines.
	int foldColNum = 70;
	
	// This variable will hold a character code.
	int charCode;
	
	// This variable stores the number of columns tab takes
	// depending on where releative to a tab stop the tab is.
	int numBlanksToPlace = TAB_SIZE;
	
	// This variable stores the number of columns we passed.
	int numInputCharsProcessed = 0;
	
	// This variable is the index for the line array.
	int strIdx = 0;
	
	int canStartWithBlanks = YES;
	
	while ( (charCode = getchar()) != EOF )
	{
		if ( ( numInputCharsProcessed < (foldColNum - 1) ) && strIdx != (MAXLINE - 2) && charCode != '\n')
		{
			if ( charCode == ' ' || charCode == '\t' )
			{
				if ( canStartWithBlanks == YES )
				{
					line[strIdx++] = charCode;
				}
			}
			else
			{
				canStartWithBlanks = YES;
				line[strIdx++] = charCode;
			}
		}
		else
		{
			while ( (strIdx - 1 >= 0) && (line[strIdx - 1] == ' ' || line[strIdx - 1] == '\t') )
				--strIdx;
			
			if ( strIdx > 0 )
			{
				line[strIdx] = '\0';
			
				printf("%s\n", line);
			}
			
			strIdx = 0;
			if ( charCode == ' ' || charCode == '\t' )
			{
				canStartWithBlanks = NO;
			}
			else
			{
				canStartWithBlanks = YES;
				
				if ( charCode != '\n' )
				{
					line[strIdx++] = charCode;
				}
			}
			
			numInputCharsProcessed = 0;
		}
		
		if ( numBlanksToPlace == 1 || charCode == '\t' ||  charCode == '\n' )
				numBlanksToPlace = TAB_SIZE;
		else
				--numBlanksToPlace;
			
		if ( charCode != '\n' )
		{
			if ( charCode == '\t' )
				numInputCharsProcessed += numBlanksToPlace;
			else
				++numInputCharsProcessed;
		}
	}
	
	if ( strIdx > 0 )
	{
		while ( (strIdx - 1 >= 0) && (line[strIdx - 1] == ' ' || line[strIdx - 1] == '\t') )
				--strIdx;
			
			if ( strIdx > 0 )
			{
				line[strIdx] = '\0';
			
				printf("%s\n", line);
			}
	}
}