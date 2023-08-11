#include "shell.h"

/**
 * main - Main entry point for shell
 * Return: 0 on success, -1 otherwise.
*/

int main(int argc, char **argv, const char **env)
{
	const char *prompt = "($)", *path_dir = "PATH";
	char **words_array = NULL;
	char *path_env = _getenv_value(env, path_dir), *line = NULL, *delim_str = " \n\t";
	char *path_exec;
	int child_pid, status;

	(void) argc;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printPrompt(prompt);

		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");

			free(line);
			free(path_env);
			return (0);
		}

		if (strempty(line))
		{
			free(line);
			continue;
		}

		words_array = getArrayOfWords(line, delim_str);

		if (strcmp(words_array[0], "exit") == 0)
		{
			free_array_words(words_array);
			free(path_env);
			free(line);
			return (0);
		}

		path_exec = _get_exec_path(path_env, words_array[0]);

		if (path_exec == NULL)
		{
			printf("%s: %i: %s: not found", argv[0], argc, words_array[0]);
			if (isatty(STDIN_FILENO))
				printf("\n");

		} else
		{
			child_pid = fork();
			if (child_pid == -1)
				return (-1);
			if(child_pid == 0)
			{
				if(execve(path_exec, words_array, NULL) == -1)
				{
					free_array_words(words_array);
					free(path_env);
					free(line);
					perror("%s\n");
					return (-1);
				}
			} else
			{
				wait(&status);
			}
		}
			
		free(line);
		free(path_exec);
		free_array_words(words_array);

	};

	free(path_env);
	return (0);
}