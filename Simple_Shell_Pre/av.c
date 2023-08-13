#include <stdio.h>

/**
 * main - stat example
 * @argc: Size of argv.
 * @argv: Array of vectors.
 * Return: Always 0.
 */

int main(int argc, char const *argv[])
{
	int i;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}
