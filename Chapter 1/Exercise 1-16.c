/* Exercise 1-16. Write a program to remove trailing blanks and tabs 
from each line of input, and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000 /* Maximum input line size */

int getline2(char string[], int lim) /* Get line into string, return length */
{
	int charCode, idx;
	for (idx = 0; idx < (lim - 1) && (charCode = getchar()) != EOF && charCode != '\n'; ++idx)
		string[idx] = charCode;
	if (charCode == '\n')
	{
		string[idx] = charCode;
		++idx;
	}
	
	string[idx] = '\0';
	
	return(idx);
}

int main()
{
	int len; /* Current line length */
	char line[MAXLINE]; /* Current input line */
	
	while ((len = getline2(line, MAXLINE)) > 0)
	{
		// A line always ends with the null character
		// Get the index of the second last character
		int last_idx = len - 1;
		
		int placeNewlineChar = (line[last_idx] == '\n');
		
		if (placeNewlineChar)
			--last_idx;

		while ((last_idx >= 0) && (line[last_idx] == ' ' || line[last_idx] == '\t'))
			--last_idx;
		
		if (last_idx >= 0)
		{
			if (placeNewlineChar)
				line[last_idx + 1] = '\n';
			
			line[last_idx + 2] = '\0';
		
			printf("%s", line);
		}
	}
}
