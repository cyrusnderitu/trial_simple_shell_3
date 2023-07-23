#include "shell.h"

/**
 */
char *path_finder(const char *command)
{
	char *path = getenv("PATH");
	char *path_tok = _strtok(path, ":");
	char *cmd_path = (char *) malloc(100);

	while (path_tok != NULL)
	{
		snprintf(cmd_path, 100, "%s/%s", path_tok, command);
		if (access(cmd_path, F_OK) == 0)
			return cmd_path;
		path_tok = _strtok(NULL, ":");
	}
	free(cmd_path);
	return NULL;
}
