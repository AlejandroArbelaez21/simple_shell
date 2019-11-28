#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char **split_str(char *str, const char *delim);
int _fork(char **temp_split);
char *_get_env(char *name);
void signal_handler (int sig);
int path_cheker(char **temp_split, char *env);
void builtsfun(char  *buffer, char **envir);
int myexit(char **temp_split, char *buffer);

/*helpers*/
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
size_t words_count(char *s);
void print_env(char **envp);
void myfree(char **pp);
int _atoi(char *s);
int _putchar(char c);

#endif
