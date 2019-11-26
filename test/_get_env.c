#include "shell.h"

/**
*_get_env - function to get the path env
*@name: pointer to env
*Return: env
*/

char *_get_env(char *name)
{
	int i = 0;
	char *env;

	while (environ[i])
	{
		if (!(_strncmp(name, environ[i], 4)))
			env = environ[i] + 5;

		i++;
	}
	return (env);
}
