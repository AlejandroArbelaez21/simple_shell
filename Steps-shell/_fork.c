 #include "shelltest.h"

 int _fork(char **temp_split)
 {

	 int status, exit_status;
	 pid_t pid;

	 pid = fork();

	 if (pid == -1)
    {
        perror("Error in child");
        return (EXIT_FAILURE);
    }
	else if (pid == 0)
	{
		if (execve(temp_split[0], temp_split, NULL) == -1)
			perror("");
		free(temp_split);
		_exit(127);
			
	}
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
		free(temp_split);
		exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
 }

int word_count(char *s)
{
	int i;
	int count = 0;
	int state = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			count++;
		}
	}
	return (count);
}
