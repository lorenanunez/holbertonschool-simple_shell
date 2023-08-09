#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Main function.
 * Return: 0 always.
 */

int main(void)
{
	char *buff;
	ssize_t bytes_read;
	size_t size = 1024;

	printf("$ ");

	buff = malloc(sizeof(char) * size);

	if (buff == NULL)
		return (-1);

	bytes_read = getline(&buff, &size, stdin);

	printf("%s\n", buff);



	return (0);
}
