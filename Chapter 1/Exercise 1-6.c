/* Counts blanks, tabs and newlines */

#include <stdio.h>

int main()
{
    int charCode;
    
    long blanks, tabs, newLines;
    blanks = tabs = newLines = 0;
    
    while((charCode = getchar()) != EOF)
    {
        if (charCode == ' ')
            ++blanks;
        else if (charCode == '\t')
            ++tabs;
        else if (charCode == '\n')
            ++newLines;
    }
    
    printf("Blanks = %ld\n", blanks);
    printf("Tabs = %ld\n", tabs);
    printf("Newlines = %ld\n", newLines);
}