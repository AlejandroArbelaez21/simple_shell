#include "shell.h"

/**
*_get_env - function to get the path env
*@envp: pointer to env
*Return: env
*/

char *_get_env(char **envp)
{
	int i = 0;
	char *env;

	while (envp[i])
	{
		if (!(_strncmp("PATH", envp[i], 4)))
			env = envp[i] + 5;
		i++;
	}
	return (env);
}
