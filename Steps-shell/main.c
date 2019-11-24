#include "shelltest.h"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	size_t buff_size = 10;
	ssize_t printer = 1;
	char **temp_split = NULL;
	char *buffer = malloc(buff_size);

	if (buffer == NULL)
	{
		perror("Failed to malloc memory");
		free(buffer);
		exit(98);
	}
	while (printer > 0)
	{
		printf("$ ");
		printer = getline(&buffer, &buff_size, stdin);
		if (printer == -1)
			break;
		printf("%s", buffer);
		temp_split = split_str(buffer, " ");
		
		_fork(temp_split);
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



