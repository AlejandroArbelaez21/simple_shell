#include "shelltest.h"

/**
 *_strcpy - Function to copy
 *@dest: edited variable
 *@src: edited variable
 *Return: always 0
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 *split_str - Function to copy
 *@str: edited variable
 *@delim: edited variable
 *Return: always 0
*/
char **split_str(char *str, const char *delim)
{
	int len = 0, numLetters = 0, i =0;
	char **token_list = NULL;
	char *tempStr = NULL;

	char *token = NULL;

	tempStr = malloc(sizeof(str));
	if (tempStr == NULL)
	{
		perror ("Error");
		free(tempStr);
		if (str[len] == '\n')
			str[len] = '\0';
	}
	
	tempStr = _strcpy(tempStr, str);

	printf("str new is: %s", tempStr);
	/*letters count*/
	while (str[len] != '\0')
	{
		if (str[len] != delim[0])
			numLetters++;
		len++;
	}

	token_list = malloc((sizeof(char) * numLetters + 1));
	printf("size of ** is %lu\n", (sizeof(char) * numLetters + 1));
	if (token_list == NULL)
	{
		perror ("Error");
		free(token_list);
	}
	token = strtok(tempStr, delim);
	while (token)
	{
		token_list[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	free(tempStr);
	return (token_list);
}
