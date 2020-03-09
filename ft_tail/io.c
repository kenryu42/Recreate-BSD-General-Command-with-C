#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "error.h"
#include "function.h"

#define BUF_SIZE 8192000
#define LINE_SIZE 1000

void	ft_puttail(char *str, int tail)
{
	int new_line;

    new_line = 0;
    while (tail != 0 && new_line <= 10)
    {
        if (str[tail] == '\n')
            new_line++;
        tail--;
    }
    if (tail)
        tail += 2;
    while (str[tail])
    {
        write(1, &str[tail], 1);
        tail++;
    }
}

void	ft_put_byte_tail(char *str, int tail, int byte)
{
    int index;

    index = tail - byte;
    if (index <= 0)
        ft_putstr(str);
    else
        ft_putstr(&str[index]);
}

void	tail_std_input(char *file, int byte)
{
	int		ret;
	char	line[LINE_SIZE + 1];

	file[0] = '\0';
	while ((ret = read(0, line, BUF_SIZE)))
	{
		line[ret] = '\0';
		ft_strcat(file, line);
	}
	if (byte)
		ft_put_byte_tail(file, ret, byte);
	else
		ft_putstr(file);
}

void	helper(int fd, char *file, int byte)
{
	int ret;

	while ((ret = read(fd, file, BUF_SIZE)))
	{
		file[ret] = '\0';
		if (byte)
			ft_put_byte_tail(file, ret, byte);
		else
			ft_puttail(file, ret);
	}
}

int		tail_files(int argc, char **argv, char *file, int byte)
{
	int i;
	int fd;
	int status;

	i = (byte > 0) ? 2 : 0; 
	status = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDWR);
		if (errno == 21)
			continue ;
		if (error_message(fd, strerror(errno), argv[i]) == -1)
		{
			status = 1;
			continue ;
		}
		if (!(byte == 0 && i == 1) && !(byte > 0 && i == 3))
			write(1, "\n", 1);
		if ((argc > 2 && !byte) || argc > 4)
			print_file_name(argv[i]);
		helper(fd, file, byte);
		close(fd);
		/*if (((argc > 2 && !byte) || argc > 4) && fd != -1 && i + 1 != argc)*/
			/*write(1, "\n", 1);*/
	}
	return (status);
}
