#include "shell.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */


int main(int argc, char **argv)
{
	int i = 1;
    pid_t my_pid, my_ppid;
	size_t buff_size = 10;
	ssize_t printer = 1;
	char **temp_split = NULL;
	char *buffer = (char *)malloc(buff_size);

	if (buffer == NULL)
	{
		perror("Failed to malloc memory");
		exit(98);
	}
	printf("%i", argc);

    my_pid = getpid();
	my_ppid = getppid();

    printf("%u\n", my_pid);
	printf("%u\n", my_ppid);

	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("This is the prompt\n");

	while (printer > 0)
	{
		printf("$ ");
		printer = getline(&buffer, &buff_size, stdin);
		printf("%s", buffer);
		temp_split = split_str(buffer, " ");
		
	}
	free(buffer);

    return (0);
}



