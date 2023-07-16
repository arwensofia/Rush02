#include <string.h>
#include "dictionary.h"

void trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    while (str[start] == ' ')
        start++;

    while (str[end] == ' ')
        end--;

    int index = 0;
    while (start <= end)
	{
        str[index] = str[start];
        index++;
        start++;
    }
    
    str[index] = '\0';
}
