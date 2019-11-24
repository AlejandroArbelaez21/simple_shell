#include "shelltest.h"
/**
 *_tokenlen - Function to copy
 *@str: value of the string
 *Return: always 0
*/
size_t tokenlen(const char *str)
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
	int len = 0, numLetters = 0, i =0, new;
	char **token_list = NULL;
	char *tempStr = NULL;
	char *token = NULL;

	tempStr = malloc(sizeof(str));
	if (tempStr == NULL)
	{
		perror ("Error");
		free(tempStr);
	}
	/*letters count*/
	while (str[len] != '\0')
	{
		if (str[len] == '\n')
			str[len] = '\0';
		if (str[len] != delim[0])
			numLetters++;
		len++;
	}
	tempStr = _strcpy(tempStr, str);
	token_list = malloc((sizeof(char *) * (numLetters + 1)));
	
	if (token_list == NULL)
	{
		perror ("Error");
		free(token_list);
	}
	token = strtok(tempStr, delim);
	while (token)
	{
		token_list[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (token_list[i] == NULL)
		{
			for(new = i; new >= 0; new--)
				free(token_list[i]);
			free(token_list);
		}
		_strcpy(token_list[i],token);
		i++;
		token = strtok(NULL, delim);
	}
	token_list[i] = NULL;
	free(tempStr);
	return (token_list);
}
