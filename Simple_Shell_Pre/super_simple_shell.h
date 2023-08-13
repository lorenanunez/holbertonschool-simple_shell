#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

char **getArrayOfWords(char *str);
void free_array_words(char **arr);
char *read_line();

#endif
