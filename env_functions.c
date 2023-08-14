#include "shell.h"

/**
 * _getenv_value - Looks for env_name in env array and returns
 * the value of the key searched allocated string if succeeded.
 * @env: Array containing all the env variables
 * @env_name: Name to look for in the env.
 * Return: An allocated string on success or NULL otherwise.
*/

char *_getenv_value(const char **env, const char *env_name)
{
	int i = 0;
	char *env_content = NULL, *env_cpy;

	if (env == NULL || env_name == NULL)
	{
		return (NULL);
	}

	while (env[i] != NULL)
	{
		if (strncmp(env_name, env[i], strlen(env_name)) == 0)
		{
			env_cpy = strdup(env[i]);
			strtok((char *)env_cpy, "=");
			env_content = strdup(strtok(NULL, "="));

			if (env_content == NULL)
			{
				return (NULL);
			}

			free(env_cpy);
			return (env_content);
		}

		i++;
	}

	return (env_content);
}

/**
 * _get_exec_path - Returns a pointer to the string
 * containing the correct path to the exec variable
 * using the PATH enviroment variable.
 * @path: Has to be the value of the key=value present in env
 * variables.
 * @exec: Name to search for in the executable.
 * Return: An allocated string on success or NULL otherwise.
*/


char *_get_exec_path(char *path, char *exec)
{
	int i = 0;
	char **array_words;
	char *dir_res;
	struct stat st;

	if (stat(exec, &st) == 0)
		return (strdup(exec));

	array_words = getArrayOfWords((char *) path, ":");

	while (array_words != NULL && array_words[i] != NULL)
	{
		dir_res = malloc(sizeof(char) * (strlen(array_words[i]) + strlen(exec) + 2));

		if (dir_res == NULL)
			return (NULL);

		strcpy(dir_res, array_words[i]);
		strcat(dir_res, "/");
		strcat(dir_res, exec);

		if (stat(dir_res, &st) == 0)
		{
			free_array_words(array_words);
			return (dir_res);
		}

		free(dir_res);
		i++;
	}

	free_array_words(array_words);
	return (NULL);
}

/**
 * print_env - Prints the enviroment variables.
 * @arr_env: Array containing the enviroment variables.
 * Return: Nothing.
*/

void print_env(const char **arr_env)
{
	int i = 0;

	while (arr_env != NULL && arr_env[i] != NULL)
	{
		printf("%s\n", arr_env[i]);
		i++;
	}
}
