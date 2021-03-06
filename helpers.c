#include "shell.h"
/**
 *_strlen - Function to copy
 *@str: value of the string
 *Return: always 0
 */
size_t _strlen(const char *str)
{
size_t len;

for (len = 0; str[len] != '\0'; len++)
	{}
return (len);
}

/**
 *_strcpy - Function to copy
 *@dest: edited variable
 *@src: edited variable
 *Return: always 0
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - writes the character n to stdout
 * @dest: Size character to print
 * @src: Size character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	/*i++;*/
	dest[i] = '\0';
	return (dest);
}

/**
 * *_realloc - writes the character n to stdout
 * @ptr: Size character to print
 * @old_size: size old of malloc
 * @new_size: size new of malloc
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a;
	int x, i;

	if (new_size > old_size)
		x = old_size;
	else
		x = new_size;
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	a = NULL;
	a = malloc(new_size);
	if (a == NULL)
		return (NULL);
	if (ptr == NULL)
		return (a);
	for (i = 0; i < x; i++)
		a[i] = ((char *) ptr)[i];
	free(ptr);
	return (a);
}

/**
 * _strncmp - function that that compares n chars of two strings
 * @s1: first value to compare
 * @s2: second value to compare
 * @n: number of chars to compare
 *
 * Return: 0 if are equal, else other number
 */
int _strncmp(char *s1, char *s2, int n)
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
	for (k = 0; k < n; k++)
	{
		if (s1[k] != s2[k])
		{
			m = (s1[k] - '0') - (s2[k] - '0');
			break;
		}
	}
	return (m);
}
