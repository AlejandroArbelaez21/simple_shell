## SIMPLE SHELL ##

## Description

In this project we will create our own shell, that is an sh-compatible command language interpreter that executes
commands read from the standard input or from a file.

## File contents

|               File                    |              Description              |
| ------------------------------------- | ------------------------------------- |
| _get_env.c                            | The file that to get the path env     |
| helpers.c                             | This file has the helps for our project |
| helper2.c                             | This is other file that has the helps for our project |
| _fork.c                               | The file has the function fork that creates proccess child |
| main.c                                | This file calls all our main functions |
| split_token.c                         | This file content the syscalls of the all functions |
| 100-atoi.c                            | Contains the function that converts a string to its integer value |
| buit.c                                | Contains the function for builts      |
| myexit.c                              | Contains the exit handle errors       |
| _putchar.c                            | function for printing one character   |
| shell.h                               | Library file                          |

## Function descriptions

|            Function                   |              Description              |
| ------------------------------------- | ------------------------------------- |
| extern char **environ;                | The function that prints              |
| char **split_str(char *str, const char *delim); | The function split the string in token |
| int _fork(char **temp_split);         | Function for creates a child proccess |
| char *_get_env(char *name);            | Function to get the path env          |
| void signal_handler (int sig);        | Action for SIGINT change              |
| int path_cheker(char **temp_split, char *env); | check the stdin in the PATH  |
| size_t _strlen(const char *str);      | Function that count the long of string |
| char *_strcpy(char *dest, char *src); | Function that copy a string in another |
| char *_strcat(char *s1, char *s2);    | Function that concatenate a string     |
| void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);| Function changes the size of the memory block pointed to by ptr to size bytes |
| int _strncmp(char *s1, char *s2, int n); | Function that that compares n chars of two strings |
| int _strcmp(char *s1, char *s2);      | function that compares two strings    |
| size_t words_count(char *s);          | Counts words because split_line is bad at arithmetic |
| void print_env(char **envp);          | Function for found the PATH |
| void myfree(char **pp);               | Frees a string of strings              |
| int _atoi(char *s)                    | convert a string to its numeric value |
| void builtsfun(char  *buffer, char **envir) | function for builts             |
| int myexit(char **temp_split, char *buffer) | function for exit handle errors program |
| int _putchar(char c);                 | Writes the character c to stdout      |

## How install the program

Our C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
To start using this version of simple shell, we must first clone the [GitHub](https://github.com/AlejandroArbelaez21/simple_shell) repository on the UNIX command line
`$ git clone https://github.com/AlejandroArbelaez21/simple_shell.git`

## Compilation

It was compiled with `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## How execute the program

After compilation, we get the executable file, the only thing we have to do is execute the file obtained in this way
`simple_shell$ ./hsh`

## Example

Our shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Date and version

28 November of 2019, version of shell 1.0

## Authors

[Alejandro Arbelaez Giraldo](https://github.com/AlejandroArbelaez21) and [Juan Sebastian Ocampo Hoyos](https://github.com/darkares23) from [Holberton School](https://www.holbertonschool.com/). :+1:
