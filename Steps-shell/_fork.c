 #include "shelltest.h"

 int _fork(char **temp_split)
 {

	 int status;
	 pid_t pid;

	 pid = fork();

	 if (pid == -1)
    {
        perror("Error");
        return (EXIT_FAILURE);
    }
	else if (pid == 0)
	{
		if (execve(temp_split[0], temp_split, NULL) == -1)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (EXIT_SUCCESS);
 }

