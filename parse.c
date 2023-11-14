#include "shell.h"

/**
* gets_cmd - A functions  that reads user inputs
* @cmd:String to be received from user
* @size: size of the string to be received
* Return: return 0 if successful, -1 on failure
*
*/
void gets_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin)) /* if end of file encountered */
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Error receiving input.\n");
			exit(EXIT_FAILURE);
		}
	}
	/* Removes newline */
	cmd[strcspn(cmd, "\n")] = '\0';
}
