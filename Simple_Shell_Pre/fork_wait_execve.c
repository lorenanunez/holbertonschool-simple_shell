#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * main - Main function.
 * Return: 0 on success, -1 if fails.
*/

int main(void)
{
	int child_pid, i = 0, status;
	const int times = 5;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < times; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
			return (-1);

		if (child_pid == 0)
		{
			printf("\nChild: %i - Parent: %i\n", getpid(), getppid());
			execve(argv[0], argv, NULL);
			return (0);

		} else
		{
			wait(&status);
			sleep(1);
		}
	}

	return (0);
}
