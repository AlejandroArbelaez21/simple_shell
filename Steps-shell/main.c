#include "shelltest.h"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	int i, k = 0;
    pid_t my_pid, my_ppid;
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
    my_pid = getpid();
	my_ppid = getppid();
    printf("%u\n", my_pid);
	printf("%u\n", my_ppid);

	printf("This is the prompt\n");

	while (printer > 0)
	{
		printf("$ ");
		printer = getline(&buffer, &buff_size, stdin);
		if (printer == -1)
			break;
		printf("%s", buffer);
		temp_split = split_str(buffer, " ");
		while(temp_split[k])
			{
			printf("token %i es %s", k, temp_split[k]);
			k++;
			}
			printf("'hola'");
		if (execve(temp_split[0], temp_split, NULL) == -1)
		{
			perror("Error:");
		}
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



