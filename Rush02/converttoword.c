#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

void convertToWord(const Dictionary *dictionary, int number)
{
    char *word = getWord(dictionary, number);
    if (word == 0)
	{
        write(1, "Dict Error\n", 11);
        exit(1);
    }
    write(1, word, strlen(word));
    write(1, "\n", 1);
}
