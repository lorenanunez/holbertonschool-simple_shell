#include "shell.h"

/**
 * main - Main entry point for shell
 * @argc: Arguments counter.
 * @argv: Vector of arguments.
 * @env: Enviroment variable.
 * Return: 0 on success, -1 otherwise.
*/

int main(int argc, char **argv, const char **env)
{
	const char *prompt = "($)", *path_dir = "PATH";
	char **words_array = NULL;
	char *path_env = _getenv_value(env, path_dir), *line = NULL;
	char *path_exec = NULL, *delim_str = " \n\t\'\"";
	int res = 0, child_exit = 0;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printPrompt(prompt);
		line = read_line();
		res = check_line(line, path_env);
		if (res == 0)
			return (child_exit);
		else if (res == -1)
			continue;
		words_array = getArrayOfWords(line, delim_str);

		if (compare_exit_code(words_array[0], words_array, line, path_env) == 0)
			return (child_exit);

		if (print_env(words_array[0], words_array, line) == 0)
			continue;

		path_exec = _get_exec_path(path_env, words_array[0]);

		if (path_exec == NULL)
			child_exit = print_errors(argv[0], argc, words_array[0]);
		else
		{
			child_exit = fork_execve(path_exec, words_array, path_env, line);
			if (child_exit == -1)
				return (-1);
		}
		free(line);
		free(path_exec);
		free_array_words(words_array);
	};
	free(path_env);
	return (0);
}
