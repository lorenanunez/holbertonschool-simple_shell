#include <stdio.h>

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
