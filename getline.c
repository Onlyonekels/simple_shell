#include "shell.h"

int main_shell(void)
{
		char *lineptr = NULL;
		size_t k = 0;
		ssize_t getlyn;

	while (1)
	{
				printf("Sshell$ ");
				getlyn = getline(&lineptr, &k, stdin);

		if (getlyn == -1)
		{
			perror("getline did fail");
			exit(EXIT_FAILURE);
		}

		if (getlyn <= 1) /* Handle empty input */
		{
			continue;
		}

				lineptr[strcspn(lineptr, "\n")] = '\0'; /* Remove newline */

				exec_cmd(lineptr);
		}

		free(lineptr);
		return (0);
}

