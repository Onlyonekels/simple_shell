#include "shell.h"
/**
 * main - A program that handles command line arguements
 * @argcount: Arguement count
 * @argvector: arguement vector
 * Return: On success, returns the pointer to the arrar
 */

int main(int argcount, char *argvector[])
{
		int k = 0;
		(void)argcount;
		while (argvector[k] != NULL)
		{
			if (strcmp(argvector[k], "mkdir") == 0)
			{

				printf("a valid command was typed\n");
				printf("%s\n", argvector[k]);
			}
			printf("argvector[%d] : %s\n", k, argvector[k]);

				k++;
		}
		return (0);
}
