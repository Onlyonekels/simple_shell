#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>

extern char **environ;

/**
 * gets_cmd - Read a line of input from the user.
 *
 * @cmd: Buffer to store the input.
 * @size: Size of the buffer.
 */

void gets_cmd(char *cmd, size_t size);

/**
 * exec_cmd - Execute a command in a child process.
 *
 * @cmd: The command to execute.
 */

void exec_cmd(const char *cmd);

/**
 * main_shell - Entry point of the shell program.
 *
 * Return: Always 0.
 */

int main_shell(void);

/**
 * get_command - Read a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user's input.
 *         NULL is returned in case of failure or EOF (Ctrl+D).
 */

char *get_command(void);

/**
 * tokenize_command - Tokenize a command into an array of strings.
 *
 * @cmd: The command to tokenize.
 *
 * Return: An array of strings representing the tokens of the command.
 */

char **tokenize_command(const char *cmd);

/**
 * free_args - Free the memory allocated for an array of strings.
 *
 * @args: The array of strings to free.
 */
void free_args(char **args);

/**
 *exit_shell - executes the exit builtin function.
 *
 */
static inline void exit_shell(void)
{
	printf("Exiting shell.\n");
	exit(EXIT_SUCCESS);
}

#endif
