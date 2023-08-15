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
	char *path_exec, *delim_str = " \n\t\'\"";
	int res;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printPrompt(prompt);

		line = read_line();
		res = check_line(line, path_env);

		if (res == 0)
			exit(0);
		else if (res == -1)
			continue;

		words_array = getArrayOfWords(line, delim_str);

		if (compare_exit_code(words_array[0], words_array, line, path_env) == 0)
			exit(0);

		path_exec = _get_exec_path(path_env, words_array[0]);

		if (path_exec == NULL)
			print_errors(argv[0], argc, words_array[0]);
		else if ((fork_execve(path_exec, words_array, path_env, line)) == -1)
			exit(-1);
		free(line);
		free(path_exec);
		free_array_words(words_array);
	};
	free(path_env);
	exit(0);
}
