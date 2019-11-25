#include "shell.h"


/**
 * signal_handler - action for SIGINT change
 * @sig: value for SIGINT
 *
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
 *@envp: env variable
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int main(int argc, char **argv)
{

int i, flag = 0, tok_indx, token_len, path_len;
size_t buff_size = 10;
ssize_t printer = 1;
struct stat cmmd_find;
char **temp_split = NULL, **catP, *env;
char *buffer = malloc(buff_size);

(void)argc, (void)argv;

	if (buffer == NULL)
	{
		perror("Failed to malloc memory");
		exit(98);
	}
	env = _get_env("PATH");
	while (printer > 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
	    	write(STDOUT_FILENO, "($) ", 4);
		printer = getline(&buffer, &buff_size, stdin);
		if (printer == -1)
			{
				if (isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "\n", 1);
				break;
			}
		if (printer > 1)
		{
			temp_split = split_str(buffer, " ");
			if (!(_strcmp(temp_split[0], "exit")))
			{
				i = 0;
				while (temp_split[i])
					i++;
				while (i >= 0)
				{
					free(temp_split[i]);
					i--;
				}
				free(temp_split);
				_exit(EXIT_SUCCESS);
			}
			else if (temp_split[0] == NULL)
			{
				perror("./hsh");
			}
			else if (!(_strcmp(temp_split[0], "env")))
			{
				print_env(environ);
			}
			if (stat(temp_split[0], &cmmd_find) == 0)
				flag = 1;
			else
			{
				catP = split_str(env, ":");
				path_len = _strlen(temp_split[0]);
				tok_indx = 0;
				while (catP[tok_indx])
				{
					token_len = strlen(catP[tok_indx]) + 2;
					catP[tok_indx] = realloc(catP[tok_indx], sizeof(char) * (token_len + path_len));
					strcat(catP[tok_indx], "/");
					strcat(catP[tok_indx], temp_split[0]);
					if (stat(catP[tok_indx], &cmmd_find) == 0)
					{
						temp_split[0] = realloc(temp_split[0], sizeof(char) * (token_len + path_len));
						strcpy(temp_split[0], catP[tok_indx]);
						flag = 1;
						break;
					}
					tok_indx++;
				}
			}
			if (flag == 1)
					_fork(temp_split);
			else
				perror("./hsh");
			i = 0;
			while (temp_split[i])
				i++;
			while (i >= 0)
			{
				free(temp_split[i]);
				i--;
			}
			free(temp_split);
			free(catP);
		}
	}
	flag = 0;
	free(buffer);
	return (0);
}

/*void exit_handler(char **prog, char **command, int cmd_count, int exit_status)
{
	long int a = 0;

	a = command[1] ? _atoi(command[1]) : 2;
	if (command[1] == NULL)
	{
		ffree(command);
		exit(exit_status);
	}

	if (a > 2147483647 || a < 0)
	{
		errno = 0;
		_error(prog, command, cmd_count);
		ffree(command);
	}
	else
	{
		ffree(command);
		exit(a);
	}
}
*/