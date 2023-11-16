#include "shell.h"

void gets_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
	if (feof(stdin))
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Error receiving input");
		exit(EXIT_FAILURE);
	}
	}

	cmd[strcspn(cmd, "\n")] = '\0'; /* Remove newline */
}

