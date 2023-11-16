#include "shell.h"
/**
 * get_command - Read a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user's input.
 *		NULL is returned in case of failure or EOF (Ctrl+D).
 */

char *get_command(void);
char *get_command(void)
{
	char *lineptr = NULL;
	size_t k = 0;
	ssize_t getlyn;

	printf("Sshell$ ");
	getlyn = getline(&lineptr, &k, stdin);

	if (getlyn == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			return (NULL);  /* End of file condition (Ctrl+D) */
		}

		else
		{
			perror("getline did fail");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
	}

	if (getlyn <= 1)
	{
		free(lineptr);
		return (NULL);  /* Handle empty input */
	}

	lineptr[strcspn(lineptr, "\n")] = '\0'; /* Remove newline */
	return (lineptr);
}

/**
 * tokenize_command - Tokenize a command into an array of strings.
 *
 * @cmd: The command to tokenize.
 *
 * Return: An array of strings representing the tokens of the command.
 */

char **tokenize_command(const char *cmd)
{
	int i;
	char *token;
	char **args = malloc(50 * sizeof(char *));

	if (!args)

	{
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

	return (args);
}

/**
 * free_args - Free the memory allocated for an array of strings.
 *
 * @args: The array of strings to free.
 */

void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; ++i)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * exec_cmd - Execute a command in a child process.
 *
 * @cmd: The command to execute.
 */

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
	}

	else

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
		}

		else
		{
			fprintf(stderr, "Command failed to execute.\n");
		}

		free_args(args);
	}
}

