#include "super_simple_shell.h"

/**
 * getArrayOfWords - This function takes str as an input and returns
 * an array with each word of this string. it uses malloc for
 * returning the right amount of memory, so it must be liberated after
 * being used.
 *
 * @str: String to split into words.
 * Return: A pointer to an array of words or NULL if failed.
*/

char **getArrayOfWords(char *str)
{
	char **res;
	char *token, *cpy_str;
	int count = 0, i = 0;

	cpy_str = strdup(str);
	token = strtok(cpy_str, " ");
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		count++;
	}

	free(cpy_str);
	res = malloc(sizeof(char **) * (count + 1));

	if (res == NULL)
		return (NULL);

	token = strtok(str, " ");

	for (i = 0; token != NULL && i < count; i++)
	{
		res[i] = strdup(token);
		token = strtok(NULL, " ");

		if (res[i] == NULL)
		{
			for (; i >= 0; i--)
				free(res[i]);

			return (NULL);
		}

	}
	res[i] = NULL;
	return (res);
}

/**
 * free_array_words - Frees an array of words and the
 * array itself.
 * @arr: Array of words to be freed.
 * Return: Nothing.
*/

void free_array_words(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		free(arr[i++]);

	free(arr);
}

/**
 * read_line - Reads a line from the standart
 * input or from piped content.
 * Return: A string containing what was readed.
*/

char *read_line()
{
	char *buff;
	ssize_t bytes_read;
	size_t size = 1024;

	printf("#cisfun ");

	buff = malloc(sizeof(char) * size);

	if (buff == NULL)
		return (NULL);

	bytes_read = getline(&buff, &size, stdin);

	if (bytes_read == -1)
		return (NULL);

	return (buff);
}
