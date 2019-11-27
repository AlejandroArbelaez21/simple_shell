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
size_t buff_size = 10;
ssize_t printer = 1;
char *buffer = NULL;
int cont = 0;

(void)argc, (void)argv;

	while (printer > 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		printer = getline(&buffer, &buff_size, stdin);
		cont = words_count(buffer);
		if (printer < 0)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (cont > 0)
		{
			builtsfun(buffer, environ);
		}
	}
	free(buffer);
	return (0);
}
