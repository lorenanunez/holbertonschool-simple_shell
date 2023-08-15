# Simple Shell

## Content
1. [Description](#description)
2. [Installation and usage](#installation&usage)
3. [Supported Features](#supported)
4. [Authors](#authors)

## Description: <a name=description><a>
This project consists of creating a UNIX command interpreter from scratch. When we first approached this project, we knew that we would need to learn multiple aspects of how UNIX handles processes, our main goal was to develop a program capable of spawning another instance of the current process and executing a command within it. This required a thorough understanding of the fork and execve system calls.

Currently, the project is capable of handling several built-in functions similar to those found in the original Bourne bash, such as exit and env. Effective memory management was also crucial, given the frequent memory allocations required by the program.

For further information, please refer to the manual page.

## Installation and usage: <a name=installation&usage><a>

Clone the repository:
`(git clone https://github.com/lorenanunez/holbertonschool-simple_shell)`

Compile the program using the following command:
`(gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh)`

After compilation an executable file named `hsh` will be generated, you can execute this program in two different modes,
the first one is the ***non-interactive*** mode, here we pass an input to it.

e.g

```bash
echo "ls -lah" | ./hsh

---> Output

total 128K
drwxr-xr-x 5 root root 4.0K Aug 14 20:06 .
drwx------ 1 root root 4.0K Aug 14 19:42 ..
drwxr-xr-x 8 root root 4.0K Aug 14 19:47 .git
-rw-r--r-- 1 root root   48 Aug  9 22:05 .gitignore
drwxr-xr-x 2 root root 4.0K Aug 10 18:05 .vscode
-rw-r--r-- 1 root root  325 Aug 13 23:18 AUTHORS
-rw-r--r-- 1 root root   23 Aug 13 23:18 README.md
drwxr-xr-x 2 root root  24K Aug 13 17:58 Simple_Shell_Pre
-rw-r--r-- 1 root root 2.0K Aug 14 14:31 aux_functions.c
-rw-r--r-- 1 root root 2.1K Aug 14 19:34 env_functions.c
-rw-r--r-- 1 root root 2.5K Aug 14 20:06 help_functions.c
-rwxr-xr-x 1 root root  18K Aug 14 20:06 hsh
-rw-r--r-- 1 root root    0 Aug 13 23:20 man_1_simple_shell
-rwxr-xr-x 1 root root  26K Aug 14 19:24 shell
-rw-r--r-- 1 root root 1.1K Aug 14 20:05 shell.c
-rw-r--r-- 1 root root  780 Aug 14 19:21 shell.h
```
We can also utilize the ***interactive mode*** by executing the program using ./hsh. Afterward, a prompt will be displayed, and the program will
wait for your input. If it identifies a corresponding program, it will execute it.

e.g

```bash
./hsh
($) ls
AUTHORS  README.md  Simple_Shell_Pre  aux_functions.c  env_functions.c  help_functions.c  hsh  man_1_simple_shell  shell  shell.c  shell.h
```

## Supported Features:<a name=supported><a>
This program supports the following built-in functions:
- exit
- env

It can also execute any function with the corresponding arguments if a directory is passed to it, or if only the name of the function that we want to execute is provided. However,
this functionality only works if the executable is located within the PATH directories.
It can handle the EOF condition too.
One main difference with sh is that the errors are printed with the replacing the name of the program with `argv[0]`

## Authors<a name=authors><a>

This code was developed by Lorena Nuñez and Facundo Sánchez.