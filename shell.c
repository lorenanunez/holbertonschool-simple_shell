#include "shell.h"

/**
 * main - Main entry point for shell
 * Return: 0 on success, -1 otherwise.
*/

int main(int argc, char **argv, const char **env)
{
	const char *prompt = "($)", *path_dir = "PATH";
	char **words_array = NULL;
	char *path_env = _getenv_value(env, path_dir), *line = NULL, *delim_str = " \n";
	char *path_exec;
	int child_pid, status;

	(void) argc;
	(void) argv;

	while (1)
	{
		printPrompt(prompt);
		line = read_line();

		if (line == NULL)
		{
			printf("\n");
			free(path_env);
			return (0);
		}

		words_array = getArrayOfWords(line, delim_str);

		if (strcmp(words_array[0], "exit") == 0)
		{
			free_array_words(words_array);
			free(path_env);
			free(line);
			return (0);
		}

		path_exec = _get_exec_path(path_env, words_array[0]);

		if (path_exec == NULL)
		{
			printf("File not found\n");

		} else
		{
			child_pid = fork();
			if (child_pid == -1)
				return (-1);
			if(child_pid == 0)
			{
				if(execve(path_exec, words_array, NULL) == -1)
				{
					perror("%s\n");
					return (-1);
				}
			} else
			{
				wait(&status);
			}
		}
			
		free(line);
		free(path_exec);
		free_array_words(words_array);

	};

	free(path_env);
	return (0);
}

/*
* TODO LIST:
* - Hacer la función _getenv(char *env_name) que devuelva la variable de entorno que le pasamos
* - Dividir con strtok el contenido de la variable separando por ':'
* - Hacer un while para iterar sobre todos los elementos del array, para cada elemento hacer un
*	stat dentro de la carpeta buscando el ejecutable que se escribió (Ej. 'ls')
*		-> Si lo encuentra, lo ejecuta
*		-> Si no lo encuentra, lanza un mensaje de error
*/