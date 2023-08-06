#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	cpy_str = strdup(str); //We have to work with a copy of the str when using strtok multiple times.
	token = strtok(cpy_str, " ");

	/**
	 * Counting how many words I have on str
	 * to allocate the right amount of mem.
	 */
	
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		count++;
	}

	free(cpy_str); //Freeing the copy.

	//Allocating memory to the pointers.

	res = malloc(sizeof(char **) * (count + 1));
	
	if (res == NULL)
		return (NULL);

	// Setting the strings into the array and getting memory for each one.

	token = strtok(str, " ");

	for (i = 0; token != NULL && i < count; i++)
	{
		res[i] = strdup(token);
		token = strtok(NULL, " ");

		/**
		 * Freeing the memory of the previous strings
		 * if one of them fails whwn we're trying to
		 * malloc them.
		 */
		
		if (res[i] == NULL)
		{
			for (; i >= 0; i--)
				free(res[i]);
			
			return NULL;
		}

	}

	//Terminating the array with NULL;

	res[i] = NULL;
	return (res);
}

int main(int argc, char *argv[])
{
	char **result;
	char *str = argv[1];
	int i = 0;
	
	if (argc < 2)
	{
		printf("You have to provide at least two arguments in (text) format.\n");
		return -1;
	}

	result = getArrayOfWords(str);

	while (result != NULL && result[i] != NULL)
		printf("[%i] - %s\n", i, result[i++]);

	return 0;
}

