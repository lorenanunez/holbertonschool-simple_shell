#include "shell.h"

/**
 * check_line - Checks if the readed line if NULL
 * and handles the case when the input is not
 * inserted from a terminal, also frees path_env
 * @line: Readed line from main.
 * @path_env: Enviroment path.
 * Return: 0 if we're not in a terminal, -1 if it's an empty line
 * 1 otherwise.
*/

int check_line(char *line, char *path_env)
{
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
		return (-1);
	}

	return (1);
}

/**
 * print_errors - Prints an error message.
 * @p_name: Program name.
 * @argc: Arguments counter.
 * @p_exec: Path exec.
 * Return: Nothing.
*/

int print_errors(char *p_name, int argc, char *p_exec)
{
	dprintf(STDERR_FILENO, "%s: %i: %s: not found\n", p_name, argc, p_exec);
	return(127);
}

/**
 * compare_exit_code - Checks if the string if equal to "exit"
 * and frees arr, line and path if it's required to.
 * @str: String to be compared.
 * @arr: Array of strings.
 * @line: Allocated readed line.
 * @path: Enviroment path.
 * Return: 0 if true, 1 otherwise.
*/

int compare_exit_code(char *str, char **arr, char *line, char *path)
{
	if (strcmp(str, "exit") == 0)
	{
		free_array_words(arr);
		free(path);
		free(line);
		return (0);
	}

	return (1);
}
/**
 * fork_execve - Creates a child an executes the corresponding
 * function specified in p_exec with the corresponding arguments
 * also frees memory if needed.
 * @p_exec: Program to be executed.
 * @w_arr: Array containing the arguments to be passed to execve.
 * @p_env: Path enviroment variable.
 * @line: String allocated in the main function.
 * Return: -1 if something fails and 0 on succeess.
*/

int fork_execve(char *p_exec, char **w_arr, char *p_env, char *line)
{
	int child_pid = fork(), status;

	if (child_pid == -1)
		return (-1);
	if (child_pid == 0)
	{
		if (execve(p_exec, w_arr, environ) == -1)
		{
			free_array_words(w_arr);
			free(p_env);
			free(line);
			perror("%s\n");
			exit(-1);
		}

	} else
	{
		wait(&status);
		return (WEXITSTATUS(status));
	}

	return (0);
}

/**
 * strempty - Determinates if a given string is empty.
 * @str: The string to determinate if it is empty.
 * Return: True if the string is empty, otherwise false.
*/

bool strempty(char *str)
{
	size_t i;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] > 32 && str[i] < 127)
		{
			return (false);
		}
	}

	return (true);
}
