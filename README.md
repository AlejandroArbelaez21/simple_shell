## SIMPLE SHELL ##

## Description

In this project we will create our own shell

## File contents

|               File                    |              Description              |
| ------------------------------------- | ------------------------------------- |
| _get_env.c                            | The file that to get the path env     |
| helpers.c                             | This file has the helps for our project |
| helpers2.c                            | This is other file that has the helps for our project |
| _fork.c                               | The file has the function fork that creates proccess child |
| main.c                                | This file calls all our main functions |
| split_token.c                         | This file content the  |
| shell.h                               | Library file                          |

## Function descriptions

|            Function                   |              Description              |
| ------------------------------------- | ------------------------------------- |
| extern char **environ;                | The function that prints              |
| char **split_str(char *str, const char *delim); | print function for numbers            |
| int _fork(char **temp_split);         | function for printing one character   |
| char *_get_env(char *name);           |                  |
| void signal_handler (int sig);        |                  |
| int path_cheker(char **temp_split, char *env); |          |
| size_t _strlen(const char *str);      |                    |
| char *_strcpy(char *dest, char *src); |                  |
| char *_strcat(char *s1, char *s2);    |                   |
| void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);                           | Library file                          |

## Compilation

It was compiled with ´gcc -Wall -Werror -Wextra -pedantic *.c -o hsh´

## Example


## Authors

Alejandro Arbelaez Giraldo and Juan Sebastian Ocampo Hoyos from Holberton School.
