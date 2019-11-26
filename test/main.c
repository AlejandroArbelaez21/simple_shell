#include "shell.h"

/**
 * signal_handler - action for SIGINT change
 * @sig: value for SIGINT
 */

void signal_handler (int sig)
{
	if (sig == SIGINT)
	write(STDOUT_FILENO, "\n($) ", 5);
}
/**
 * main - void
 *@argc: arg count
 *@argv: array of parameters
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int main(int argc, char **argv)
{
int flag = 0;
size_t buff_size = 10;
ssize_t printer = 1;
struct stat cmmd_find;
char **temp_split = NULL, *env, *buffer = NULL;

(void)argc, (void)argv;
	env = _get_env("PATH");
	while (printer > 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		printer = getline(&buffer, &buff_size, stdin);
		if (printer < 0)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
				free(buffer);
				exit(EXIT_SUCCESS);
		}
		if (printer > 1)
		{
			temp_split = split_str(buffer, " \t");
			if (!(_strcmp(temp_split[0], "exit")))
			{
				myfree(temp_split);
				free(buffer);
				_exit(EXIT_SUCCESS);
			}
			else if (temp_split[0] == NULL)
				perror("./hsh");
			else if (!(_strcmp(temp_split[0], "env")))
				print_env(environ);
			if (stat(temp_split[0], &cmmd_find) == 0)
				flag = 1;
			else
				flag = path_cheker(temp_split, env);
			if (flag == 1)
				_fork(temp_split);
			else
				perror("./hsh");
				myfree(temp_split);
		}
		flag = 0;
	}
	free(buffer);
	return (0);
}
