 #include "shelltest.h"

 int _fork(char **temp_split)
 {
	 char **temp_copy = _strcpy(temp_copy, temp_split);
	 pid_t pid = fork();
	 int status;
	 if (pid == -1)
    {
        perror("Error");
        return (EXIT_FAILURE);
    }
	else if (pid == 0)
	{
		if (execve(temp_copy[0], temp_copy, NULL) == -1)
		{
			perror("Error");
		}
		free(temp_copy);
	}
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (EXIT_SUCCESS);
 }

