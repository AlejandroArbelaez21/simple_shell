#include "shell.h"
/**
 * _fork - create a child process
 * @temp_split: get copy of the file
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _fork(char **temp_split)
{
pid_t pid = fork();
int status;

	if (pid == -1)
	{
	perror("Error");
	return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(temp_split[0], temp_split, environ) < 0)
		{
			perror("Error");
		}
		free(temp_split);
		exit(127);
	}
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (EXIT_SUCCESS);
}
