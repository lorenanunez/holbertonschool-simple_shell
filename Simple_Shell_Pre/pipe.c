#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Main function that prints piped content.
 * @argc: Arguments counter.
 * @argv: ARguments vector.
 * Return: 0 always.
*/

int main(int argc, char *argv[])
{
	size_t size;

	if (!isatty(STDIN_FILENO))
	{

		int i = 0;
		char *pipe, *str;

		getline(&str, &size, stdin);
		pipe = strtok(str, " \n");

		fprintf(stdout, "piped content: >>%s<<\n", pipe);
		free(str);
	}

	return (0);
}
