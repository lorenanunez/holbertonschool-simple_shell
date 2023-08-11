#include "shell.h"

/**
 * strempty - Determinates if a given string is empty.
 *
 * @str: The string to determinate if it is empty. 
 *
 * Return: True if the string is empty, otherwise false.
*/

bool strempty(char *str)
{
    size_t i;

    if (str == NULL)
    {
        return (NULL);
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] > 32 && str[i] < 127)
        {
            return (false);
        }
    }

    return (true);
}
