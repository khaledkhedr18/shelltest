#ifndef KHEDIRA_SHELL_H
#define KHEDIRA_SHELL_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGINPUT_SIZE 100
#define MAX_ARGUMENTS 10

void khedira_prompt();
void khedira(const char *output);
void khedira_uinput(char *comm, size_t size);
void khedira_exec(char *exec_comm, char *args[]);
int khedira_tokenize(char *myinp, char *myargs[]);

#endif
