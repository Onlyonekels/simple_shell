#include "shell.h"
/**
 * main - This is the main entry point for a shell program.
 * Return: Always (0) on success.
 */

int main(void)
{
	char cmd[140];

	while (1)
	{
		printf("Sshell$ ");
		gets_cmd(cmd, sizeof(cmd));
		exec_cmd(cmd);
	}
	return (0);
}

