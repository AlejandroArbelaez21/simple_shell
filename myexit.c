#include "shell.h"
/**
 * myexit - exit handle errors
 * @temp_split: 2d array with the promt splited
 * @buffer: promt str
*/
int myexit(char **temp_split, char *buffer)
{
	int arg_exit = 0, len_exit = 0, flag = 0;
	if (temp_split[1] == NULL || (!_strcmp(temp_split[1], "0")))
	{
		myfree(temp_split);
		free(buffer);
		exit(0);
	}
	arg_exit = _atoi(temp_split[1]);
	if (arg_exit > 0 && arg_exit <= 255)
	{
		myfree(temp_split);
		free(buffer);
		exit(arg_exit);
	}
	else
	{
		len_exit = _strlen(temp_split[1]);
		write(STDOUT_FILENO, "exit: Illegal number: ", 22);
		write(STDOUT_FILENO, temp_split[1], len_exit);
		write(STDOUT_FILENO, "\n", 1);
		flag = 2;
	}
	return (flag);
}