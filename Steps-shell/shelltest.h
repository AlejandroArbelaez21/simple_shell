#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
char **split_str(char *str, const char *delim);

char *_strcpy(char *dest, char *src);


#endif
