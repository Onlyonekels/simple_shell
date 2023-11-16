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

void gets_cmd(char *cmd,size_t size);
void exec_cmd(const char *cmd);
int main_shell(void);

#endif
