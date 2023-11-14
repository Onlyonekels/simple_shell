#include "shell.h"

/**
 * exec_cmd - Executes the user command.
 * @cmd: String to be executed
 */
void exec_cmd(const char *cmd)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork Error");
		exit(EXIT_FAILURE);
	}
	/* Child process */
	else if (child_pid == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("Exec Error");
		exit(EXIT_FAILURE);
	}
	/* Parent process */
	else
	{
		wait(NULL);
	}
}
