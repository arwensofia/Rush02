#include <string.h>
#include "dictionary.h"

char *getWord(const Dictionary *dictionary, int number)
{
    int i = 0;
    while (i < dictionary->count)
	{
        if (dictionary->dict[i].number == number)
		{
            return dictionary->dict[i].word;
        }
        i++;
    }
    return (0);
}
