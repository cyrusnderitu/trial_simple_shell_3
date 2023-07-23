#include "shell.h"

/**
 * _execve - executes passed command and calls fork
 * @command: points the command to be executed
 */
void _execve(char *command)
{
	char *args[3];
	int status;
	pid_t pid = fork();

	args[0] = command;
	args[1] = NULL;

	if (pid == 0)
	{
		execve(command, args, NULL);
		fprintf(stderr, "./hsh: No such file or directory\n");
		exit(1);
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		print_error("fork failed");
		exit(1);
	}
}
