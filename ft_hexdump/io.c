#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "ft.h"
#include "ft_2.h"
#include "io_op.h"
#include "error.h"

#define BUF_SIZE 4096000
#define LINE_SIZE 1000

void	print_hexline(int nb, int option_C)
{
	int hex_len;
	int prefix;

	hex_len = (ft_count_hex(nb) == 1) ? 2 : (ft_count_hex(nb));
	prefix = (option_C) ? (7 - hex_len) : (6 - hex_len);
	while (prefix--)
		write(1, "0", 1);
	ft_puthex(nb, 0);
	if (option_C)
		write(1, "0  ", 3);
	else
		write(1, "0 ", 2);
}

void	print_total_hex(int total, int option_C)
{
	int hex_len;
	int prefix;

	hex_len = (ft_count_hex(total) == 1) ? 2 : (ft_count_hex(total));
	prefix = (option_C) ? (8 - hex_len) : (7 - hex_len);
	while (prefix--)
		write(1, "0", 1);
	ft_puthex(total, 0);
	write(1, "\n", 1);
}

void	print_hexdump(char *file)
{
	int i;
	int index;
	int line_nb;

	index = 0;
	line_nb = 0;
	while (file[index])
	{
		i = 0;
		print_hexline(line_nb++, 0);
		while (i < 16 && file[index])
		{
			ft_puthex(file[index++], 0);
			if (i != 15)
				write (1, " ", 1);
			i++;
		}
		if (i == 16)
			write(1, "\n", 1);
	}
	if (i < 16)
		print_padding(i, 0);
	print_total_hex(index, 0);
}

void	hexdump_stdi(char *file, char *line, int option_C)
{
	int ret;

	while ((ret = read(0, line, LINE_SIZE))) 
	{
		line[ret] = '\0';
		ft_strcat(file, line);
	}
	if (option_C)
		print_hexdump_option(file);
	else
		print_hexdump(file);
}

void	hexdump_files(int argc, char **argv, char *file, int option_C)
{
	int i;
	int fd;
	int ret;
	char files[BUF_SIZE + 1];

	i = (option_C) ? 1 : 0;
	files[0] = '\0';
	while (++i < argc)
	{
		fd = open(argv[i], O_RDWR);
		if (fd == -1)
			print_error_message(argv[i], strerror(errno), errno, i + 1 == argc);
		else
		{
			while ((ret = read(fd, file, BUF_SIZE)))
			{
				file[ret] = '\0';
				ft_strcat(files, file);
			}
			close(fd);
		}
	}
	if (option_C && *files)
		print_hexdump_option(files);
	else if (*files)
		print_hexdump(files);
}
