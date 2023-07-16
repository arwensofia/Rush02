#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

int main(int argc, char *argv[])
{
    char *numberStr;
    int i;
    Dictionary dictionary;
    int number;

    if (argc < 2 || argc > 3)
	{
        write(1, "Error: Invalid arguments\n", 26);
        write(1, "Usage: ", 7);
        write(1, argv[0], strlen(argv[0]));
        write(1, " <number> [<dictionary_file>]\n", 30);
        return (1);
    }

    numberStr = argv[1];
    if (numberStr[0] == '\0')
	{
        write(1, "Error: Number cannot be empty\n", 30);
        return (1);
    }

    i = 0;
    while (numberStr[i] != '\0') {
        if (numberStr[i] < '0' || numberStr[i] > '9')
		{
            write(1, "Error: Invalid number\n", 22);
            return (1);
        }
        i++;
    }

    if (argc == 3)
	{
        char *dictionaryFile = argv[2];
        parseDict(&dictionary, dictionaryFile);
    } else
	{
        parseDict(&dictionary, "numbers.dict");
    }

    number = atoi(numberStr);
    convertToWord(&dictionary, number);

    return 0;
}
