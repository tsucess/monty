#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point for monty interp
 *
 * @argc: the count param
 * @argv: pointer param to an array of char
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int ext_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(scritp_fd);
	fclose(script_fd);
	return (ext_code);
}
