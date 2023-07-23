#include "shell.h"

/**
 * main - entry point to compile
 * Return: 0 on success
 */
int main(void)
{
	char command[100];
	char *token;
	char *argv1[100];
	int i = 0, j = 0;
	int status;
	pid_t pid;

	if (isatty(fileno(stdin)))
	{
		while (1)
		{
			printf("#cisfun$ ");
			fgets(command, sizeof(command), stdin);
			if (command[_strlen(command) - 1] == '\n')
				command[_strlen(command) - 1] = '\0';
			if (_strcmp(command, "exit") == 0)
				break;
			token = _strtok(command, " ");
			while (token != NULL)
			{
				argv1[i] = token;
				i++;
				token = _strtok(NULL, " ");
			}
			argv1[i] = NULL;

			pid = fork();

			if (pid == 0)
			{
				execve(argv1[0], argv1, NULL);
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
	}
	else
	{
		while (fgets(command, sizeof(command), stdin) != NULL)
		{
			if (command[_strlen(command) - 1] == '\n')
				command[_strlen(command) - 1] = '\0';
			if (_strcmp(command, "exit") == 0)
				break;

			token = _strtok(command, " ");
			while (token != NULL)
			{
				argv1[j] = token;
				j++;
				token = _strtok(NULL, " ");
			}
			argv1[j] = NULL;

			pid = fork();

			if (pid == 0)
			{
				execve(argv1[0], argv1, NULL);
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
	}
	return (0);
}
