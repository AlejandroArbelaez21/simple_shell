#include "shell.h"
/**
 * words_count - counts words because split_line is bad at arithmetic
 * @s: string to count
 * Return: number of words
 */

size_t words_count(char *s)
{
	int i;
	int count = 0;
	int state = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			count++;
		}
	}
	return (count);
}
/**
 * print_env - function for found the PATH
 * @envp: pointer with the enviroment
 *
 */
void print_env(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
 * _strcmp - function that that compares n chars of two strings
 * @s1: first value to compare
 * @s2: second value to compare
 *
 * Return: 0 if are equal, else other number
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, k, m = 0;

	while (s1[i] != 0)
	{
		i++;
	}
	while (s2[j] != 0)
	{
		j++;
	}
	for (k = 0; k < i && k < j; k++)
	{
		if (s1[k] != s2[k])
		{
			m = (s1[k] - '0') - (s2[k] - '0');
			break;
		}
	}
	return (m);
}
/**
 * myfree - frees a string of strings
 * @pp: string of strings
 *
 * Return: 0 exit success
 */
void myfree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
*path_cheker - function to check the path of the commd
*@temp_split: array 2d of tokens
*@env: env var
*Return: flag
*/
int path_cheker(char **temp_split, char *env)
{
	char **catP;
	int path_len, tok_len, tok_ind, flag = 0;
	struct stat cmmd_find;

	catP = split_str(env, ":");
	path_len = _strlen(temp_split[0]);
	tok_ind = 0;
	while (catP[tok_ind])
	{
		tok_len = _strlen(catP[tok_ind]) + 2;
		catP[tok_ind] = realloc(catP[tok_ind], sizeof(char) * (tok_len + path_len));
		_strcat(catP[tok_ind], "/");
		_strcat(catP[tok_ind], temp_split[0]);
		if (stat(catP[tok_ind], &cmmd_find) == 0)
		{
			temp_split[0] = realloc(temp_split[0], sizeof(char) * (tok_len + path_len));
			_strcpy(temp_split[0], catP[tok_ind]);
			flag = 1;
			break;
		}
		tok_ind++;
	}
	myfree(catP);
	return (flag);
}
