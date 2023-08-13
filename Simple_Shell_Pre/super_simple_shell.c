#include "super_simple_shell.h"

/**
 * main - Main function that creates a child proccesss.
 * Return: 0 on Success, -1 if fails.
*/

int main(void)
{
	int child_pid, status;
	char **argv, *str;

	while (1)
	{
		child_pid = fork();

		if (child_pid == -1)
			return (-1);
		if (child_pid == 0)
		{
			str = strtok(read_line(), "\n");
			argv = (getArrayOfWords(str));

			if (strcmp(argv[0], "exit") == 0)
				return (0);

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				return (-1);
			}
			free_array_words(argv);
			free(str);

		} else
			wait(&status);
	}

	return (0);
}
