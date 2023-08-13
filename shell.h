#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
char *_getenv_value(const char **env, const char *env_name);
char *_get_exec_path(char *path, char *exec);
bool strempty(char *str);
int check_line(char *line, char *path_env);
void print_errors(char *p_name, int argc, char *p_exec);
int compare_exit_code(char *str, char **arr, char *line, char *path);
int fork_execve(char *p_exec, char **w_arr, char *p_env, char *line);

#endif
