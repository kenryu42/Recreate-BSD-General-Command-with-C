#include <fcntl.h>
#include <unistd.h>
#include "ft.h"
#include "io.h"
#include "ft_2.h"
#include "io_op.h"

#define BUF_SIZE 4096000
#define LINE_SIZE 1000

int		main(int argc, char **argv)
{
	char	file[BUF_SIZE + 1];
	char	line[LINE_SIZE + 1];

	file[0] = '\0';
	if (argc == 1)
		hexdump_stdi(file, line, 0);
	else if (argc == 2 && ft_strcmp(argv[1], "-C") == 0)
		hexdump_stdi(file, line, 1);
	else if (ft_strcmp(argv[1], "-C") == 0)
		hexdump_files(argc, argv, file, 1);
	else
		hexdump_files(argc, argv, file, 0);
}
