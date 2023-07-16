#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

void parseDict(Dictionary *dictionary, const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
	{
        write(1, "Dictionary Error\n", 17);
    }

    char buffer[1024];
    int index = 0;

    while (read(fd, buffer, sizeof(buffer)) > 0)
	{
        char *line = strtok(buffer, "\n");

        while (line != 0)
		{
            trim(line);

            char *colon = strchr(line, ':');
            if (colon == 0)
			{
                write(1, "Dictionary Error\n", 18);
                exit(1);
            }

            *colon = '\0';
            int num = atoi(line);
            char *word = colon + 1;

            dictionary->dict[index].number = num;
            dictionary->dict[index].word = strdup(word);

            index++;
            line = strtok(0, "\n");
        }
    }

    dictionary->count = index;

    close(fd);
}
