#include "shell.h"
/**
 * main - void
 *@argc: arg count
 *@argv: array of parameters
 *@envp: env variable
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int main(int argc, char **argv, char **envp)
{
int i, flag, tok_indx, token_len, path_len;
size_t buff_size = 10;
ssize_t printer = 1;
pid_t pid;
struct stat cmmd;
char **temp_split = NULL, **catP, *env;
char *buffer = malloc(buff_size), *env;
(void)argc, (void)argv;

	if (buffer == NULL)
	{
		perror("Failed to malloc memory");
		free(buffer);
		exit(98);
	}
	env = _get_env(envp);
	while (printer > 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		printer = getline(&buffer, &buff_size, stdin);
		if (printer == -1)
			break;
		write(STDOUT_FILENO, "$ ", 2);
		temp_split = split_str(buffer, " ");
		if (stat(temp_split[0], &cmmd) == 0)
		{
			flag = 1;
		}
		else
		{
			catP = split_string(env, ":");
			path_len = _strlen (temp_split[0]);
			tok_indx = 0;
			while (catP[tok_indx])
			{
				token_len = _strlen(catP[tok_indx] + 2);
				catP[tok_indx] = realloc(catP[tok_indx], sizeof(char) * (token_len + path_len));
				_strcat(catP[tok_indx], "/");
				_strcat(catP[tok_indx], temp_split[0]);
				if (stat(catP[tok_indx], &cmmd) == 0)
				{
					temp_split[0] = realloc(temp_split[0], sizeof(char) * (token_len + path_len));
					strcpy(temp_split[0], catP[tok_indx]);
					flag = 1;
					break;
				}
				tok_indx++;
			}
		}
		pid = _fork(temp_split);
		if (printer > 1)
			write(STDOUT_FILENO, buffer, printer);
		i = 0;
		while (temp_split[i])
			i++;
		while (i >= 0)
		{
			free(temp_split[i]);
			i--;
		}
		free(temp_split);
	}
	free(buffer);
return (0);
}
