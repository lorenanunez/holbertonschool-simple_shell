#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char **getArrayOfWords(char *str, char *delim);
void free_array_words(char **arr);
char *read_line();
void printPrompt(const char *str);
char *_getenv_value(const char **env, const char* env_name);
char *_get_exec_path(char *path, char *exec);

#endif
