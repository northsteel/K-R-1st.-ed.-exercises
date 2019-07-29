/* Exercise 1-15. Write a program to print all lines that are longer 
than 80 characters. */

#include <stdio.h>

#define MAXLINE 1000 /* Maximum input line size */
#define MIN_LINE_LENGTH 80

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
		if (len > MIN_LINE_LENGTH)
		{			
			printf("%s", line);
		}
}
