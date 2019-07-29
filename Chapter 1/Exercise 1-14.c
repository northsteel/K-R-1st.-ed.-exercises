/* Exercise 1-14. Revise the main routine of the longest-line program 
so it will correctly print the length of arbitrarily long input lines,
and as much as possible of the text */

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

void copy(char str1[], char str2[]) /* Copy s1 to s2; Assume s2 big enough */
{
	int idx;
	
	idx = 0;
	while ((str2[idx] = str1[idx]) != '\0')
		++idx;
}

int main()
{
	int len; /* Current line length */
	int max; /* Maximum length seen so far */
	char line[MAXLINE]; /* Current input line */
	char save[MAXLINE]; /* Longest line, saved */
	
	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(line, save);
		}
		
	if (max > 0) /* There was a line */
	{
		printf("Longest line length is %d characters.\n", max);
		printf("%s", save);
	}
}
