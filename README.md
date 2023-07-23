# 0x16. C - Simple Shell

## Requirements

### General

- Allowed editors: vi, vim, emacs
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Header files should be include guarded
- AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

## More Info

### Output

- Unless specified otherwise, the program must have the exact same output as **sh (/bin/sh)** as well as the exact same error output.

Example of error with **sh**:

	$ echo "qwerty" | /bin/sh
	/bin/sh: 1: qwerty: not found
	$ echo "qwerty" | /bin/../bin/sh
	/bin/../bin/sh: 1: qwerty: not found
	$

## List of allowed functions and system calls

- access
- chdir
- close
- execve
- exit
- fflush
- fork
- free
- getline
- malloc
- isatty
- kill
- open
- read
- signal
- wait
- write
- strtok
- getpid

### Compilation

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Testing

	$ ./hsh
	($) /bin/ls
	hsh main.c shell.c
	($)
	($) exit
	$

Test should also be in non-interactive mode

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

