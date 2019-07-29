/* Exercise 1-17. Write a function reverse (s) which reverses the 
character string s. Use it to write a program which reverses its
input a line at a time. */

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

void reverse(char str[], int length, char reversed_str[])
{
	// Skip the null character
	length -= 2;
	
	int placeNewlineChar = str[length] == '\n';
	if (placeNewlineChar)
		--length;
	
	int idx = 0;
	while (length >= 0)
		reversed_str[idx++] = str[length--];
	
	if (placeNewlineChar)
		reversed_str[idx++] = '\n';
	
	reversed_str[idx] = '\0';
}

int main()
{
	int line_last_idx; /* Last line index */
	char line[MAXLINE]; /* Current input line */
	
	while ((line_last_idx = getline2(line, MAXLINE)) > 0)
	{
		char reversed_str[line_last_idx + 1];
		reverse(line, line_last_idx + 1, reversed_str);
		
		printf("%s", reversed_str);
	}
}
