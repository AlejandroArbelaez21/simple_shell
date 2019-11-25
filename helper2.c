#include "shell.h"
/**
 * word_count - counts words because split_line is bad at arithmetic
 * @s: string to count
 * Return: number of words
 */

int words_count(char *s)
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
 * _strncmp - function that that compares n chars of two strings
 * @s1: first value to compare
 * @s2: second value to compare
 * @n: number of chars to compare
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