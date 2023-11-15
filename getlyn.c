#include "shell.h"
/**
 * main - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @k: The size of lineptr.
 * @getlyn: The stream to read from.
 * Return: The number of bytes read.
 */

int main(char *lineptr, size_t k, ssize_t getlyn)
{
		char *lineptr;
		size_t k;
		ssize_t getlyn;

		getlyn = getline(&lineptr, &k, STDIN_FILENO);
		if (getlyn == -1)
		{
			perror("getline did fail");
			exit(-1);
		}
		printf("%s\n", lineptr);

		return (0);

}
