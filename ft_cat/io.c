#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "function.h"

#define BUF_SIZE 80000

int		error_message(char *path_name)
{
	int fd;

	fd = open(path_name, O_RDWR);
	if (fd == -1)
		ft_put_stderr(strerror(errno), path_name);
	else
		close(fd);
	return (fd);
}

void    read_std_output(char *file)
{
    int ret;

    while ((ret = read(0, file, BUF_SIZE)))
    {
    	file[ret] = '\0';
        ft_putstr(file);
	}
}

int		display_files(int argc, char **argv, char *file)
{
    int i;
    int fd;
    int ret;
	int	error;

    i = 0;
	error = 0;
    while (++i < argc)
    {
		if (error_message(argv[i]) == -1)
		{
			error = -1;
			continue ;
		}
		fd = open(argv[i], O_RDONLY);
        while ((ret = read(fd, file, BUF_SIZE)))
        {
            file[ret] = '\0';
    		ft_putstr(file);
        }
        close(fd);
    }
	return (error);
}
