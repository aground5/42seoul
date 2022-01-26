#include <libgen.h>
#include <errno.h>
#include <string.h>

#include "ft_tail.h"

void	print_illegal_offset(int argc, char **argv)
{

}


void	print_file_error(char *pgname, char *filename, char *err_msg)
{
	pgname = basename(pgname);
	write(1, pgname, ft_strlen(pgname));
	write(1, ": ", 2);
	write(1, filename, ft_strlen(filename));
	write(1, ": ", 2);
	write(1, err_msg, ft_strlen(err_msg));
	write(1, "\n", 1);
}
