/* Exercise 1-22. Write a program to remove all comments from a C 
program. Don't forget to handle quoted strings and character constants 
properly. */

#include <stdio.h>

#define YES 1
#define NO 0

int main()
{
	int prevCharCode = '\0';
	int charCode;
	int isCharConst = NO;
	int isString = NO;
	int escapingNextChar = NO;
	while ( ( charCode = getchar() ) != EOF )
	{
		if ( isString == NO && isCharConst == NO)
		{
			if ( charCode == '"')
				isString = YES;
			else if ( charCode == '\'' )
				isCharConst = YES;
			else if ( ( charCode == '*' || charCode == '/' ) && ( prevCharCode == '/' ) )
			{
				int isSingleLineComment;
				if ( charCode == '*' )
					isSingleLineComment = NO;
				else
					isSingleLineComment = YES;
				
				while ( ( charCode = getchar() ) != EOF )
				{
					if ( ( charCode == '\n' && isSingleLineComment == YES )
					|| ( charCode == '/' && prevCharCode == '*' && isSingleLineComment == NO ) )
					{
						charCode = '\n';
						break;
					}
					
					prevCharCode = charCode;
				}
				
				prevCharCode = '\0';
			}
		}
		else
		{
			if ( escapingNextChar == NO )
			{
				if ( charCode == '\\' )
					escapingNextChar = YES;
				else if ( charCode == '"' && isString == YES )
					isString = NO;
				else if ( charCode == '\'' && isCharConst == YES )
					isCharConst = NO;
			}
			else
				escapingNextChar = NO;
		}
		
		if ( prevCharCode != '\0' )
			putchar(prevCharCode);
		
		prevCharCode = charCode;
	}
	
	if ( prevCharCode != '\0' )
		putchar(prevCharCode);
}