/* Exercise 1-21. Write a program to "fold" long input lines after the 
last non-blank character that occurs before the n-th column of input,
where n is a parameter. Make sure your program does something intelligent
with very long lines, and if there are no blanks or tabs before the 
specified column */

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
	int numChar = 0;
	
	// This variable is the index for the line array.
	int strIdx = 0;
	
	int canStartWithBlanks = YES;
	
	while ( (charCode = getchar()) != EOF )
	{
		if ( ( numChar < (foldColNum - 1) ) && strIdx != (MAXLINE - 2) && charCode != '\n')
		{
			if ( charCode == ' ' || charCode == '\t' )
			{
				if ( canStartWithBlanks == YES )
				{
					line[strIdx++] = charCode;
					
					if ( charCode == '\t' )
					{
						numChar += numBlanksToPlace;
					}
					else
						++numChar;
				}
			}
			else
			{
				canStartWithBlanks == YES;
				line[strIdx++] = charCode;
				++numChar;
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
			
			numChar = 0;
			strIdx = 0;
			if ( charCode == ' ' || charCode == '\t' )
				canStartWithBlanks = NO;
			else
			{
				canStartWithBlanks = YES;
				
				if ( charCode != '\n' )
				{
					line[strIdx++] = charCode;
					++numChar;
				}
			}
		}
		
		if ( numBlanksToPlace == 1 || charCode == '\t' ||  charCode == '\n' )
				numBlanksToPlace = TAB_SIZE;
		else
				--numBlanksToPlace;
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