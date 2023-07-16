#ifndef DICTIONARY_H
#define DICTIONARY_H

#define DICT_SIZE 100

typedef struct
{
    int number;
    char *word;
} Entry;

typedef struct
{
    Entry dict[DICT_SIZE];
    int count;
} Dictionary;

void trim(char *str);
void parseDict(Dictionary *dictionary, const char *filename);
char *getWord(const Dictionary *dictionary, int number);
void convertToWord(const Dictionary *dictionary, int number);

#endif // DICTIONARY_H
