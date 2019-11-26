#include "shell.h"
/**
* builtsfun - function for builts
*@buffer:  get line buffer
*@envir: env
*/
void builtsfun(char  *buffer, char **envir)
{
		int flag = 0;
	struct stat cmmd_find;
	char **temp_split = NULL, *env;

	env = _get_env("PATH");
	temp_split = split_str(buffer, " \t");

	if (!(_strcmp(temp_split[0], "exit")))
		flag = myexit(temp_split, buffer);
	else if (temp_split[0] == NULL)
		perror("./hsh");
	else if (!(_strcmp(temp_split[0], "env")))
		print_env(envir);
	if (stat(temp_split[0], &cmmd_find) == 0)
		flag = 1;
	else
		flag = path_cheker(temp_split, env);
	if (flag == 1)
		_fork(temp_split);
	else
		perror("./hsh");
	myfree(temp_split);
}
