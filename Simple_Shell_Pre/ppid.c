#include <stdio.h>
#include <unistd.h>

/**
 * main - Function that the pid of the parent proccess
 * Return: 0 always.
*/

int main(void)
{
	printf("%i", getppid());
	return (0);
}
