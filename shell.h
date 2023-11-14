#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void gets_cmd(char *cmd,size_t size);
void exec_cmd(const char *cmd);

#endif
