#include "shell.h"

extern char **environ;

char **tokenize_command(const char *cmd)
{
		int i = 0;
		char *token;
		char **args = malloc(50 * sizeof(char *));
		if (!args) {
				perror("Malloc Error");
				exit(EXIT_FAILURE);
		}

		/* Tokenize the input command */
		token = strtok((char *)cmd, " ");
		while (token != NULL && i < 50)
		{
				args[i++] = strdup(token);
				token = strtok(NULL, " ");
		}
		args[i] = NULL;

		return args;
}

void free_args(char **args)
{
		int i;

		for (i = 0; args[i] != NULL; ++i)
		{
				free(args[i]);
		}
		free(args);
}

void exec_cmd(const char *cmd)
{
		pid_t child_pid;
		char **args = tokenize_command(cmd);

		/* Check if the file is executable */
		if (access(args[0], X_OK) == -1)
		{
				fprintf(stderr, "Error: %s is not executable or does not exist.\n", args[0]);
				free_args(args);
				return;
		}

		child_pid = fork();

		if (child_pid == -1)
		{
				perror("Fork Error");
				free_args(args);
				exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
				close(STDOUT_FILENO);
				close(STDERR_FILENO);

				if (execve(args[0], args, environ) == -1)
				{
						perror("Execve Error");
						free_args(args);
						exit(EXIT_FAILURE);
				}
		} else
		{
				int status;
				if (waitpid(child_pid, &status, 0) == -1)
				{
						perror("Waitpid Error");
						free_args(args);
						exit(EXIT_FAILURE);
				}

				if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				{
						printf("Command executed successfully!\n");
				} else {
						fprintf(stderr, "Command failed to execute.\n");
				}

				free_args(args);
		}
}
