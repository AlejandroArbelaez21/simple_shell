#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **envp;

char **split_str(char *str, const char *delim);
int _fork(char **temp_split);
char *_get_env(char **envp);

/*helpers*/
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strncmp(char *s1, char *s2, int n);


#endif
