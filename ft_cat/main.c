#include "io.h"
#include "function.h"

#define BUF_SIZE 8192000

int		main(int argc, char *argv[])
{
	char	file[BUF_SIZE + 1];

	if (argc == 1 || (ft_strcmp(argv[1], "-") == 0 && argc == 2))
		read_std_output(file);
	else if (display_files(argc, argv, file) == -1)
		return (1);
	return (0);
}
