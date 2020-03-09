#include <unistd.h>
#include "function.h"


void	ft_puterr(char *str, char *path_name)
{
	write(2, "ft_tail: ", 9);
    while (*path_name)
        write(2, path_name++, 1);
    write(2, ": ", 2);
    while (*str)
        write(2, str++, 1);
	write(2, "\n", 1);
}

int		error_message(int fd, char *error_msg, char *file_name)
{
	if (fd == -1)
		ft_puterr(error_msg, file_name);
	return (fd);
}

void	error_offset(char *file_name)
{
	write(2, "ft_tail: illegal offset -- ", 27);
	while (*file_name)
		write(2, file_name++, 1);
	write(2, "\n", 1);
}
