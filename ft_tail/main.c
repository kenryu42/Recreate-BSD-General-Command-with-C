#include "io.h"
#include "error.h"
#include "function.h"

#define BUF_SIZE 8192000

int		main(int argc, char **argv)
{
	char file[BUF_SIZE + 1];

	if (argc == 1)
		tail_std_input(file, 0);
	else if (argc == 3 && ft_strcmp(argv[1], "-c") == 0)
	{
		if (ft_atoi(argv[2]) == -1)
		{
			error_offset(argv[2]);
			return (1);
		}
		tail_std_input(file, ft_atoi(argv[2]));
	}
	else if (ft_strcmp(argv[1], "-c") == 0)
	{
		if (ft_atoi(argv[2]) == -1)
		{
			error_offset(argv[2]);
			return (1);
		}
		return (tail_files(argc, argv, file, ft_atoi(argv[2])));
	}
	else
		return (tail_files(argc, argv, file, 0));
}
