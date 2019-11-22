#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

char **split_str(char *str, const char *delim);
int _fork(char **temp_split);

/*helpers*/
size_t tokenlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strncmp(char *s1, char *s2, int n);

#endif
