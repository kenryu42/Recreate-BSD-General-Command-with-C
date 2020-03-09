#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 8000000

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char **argv)
{
	int	fd;
	int ret;
	char file[BUF_SIZE + 1];

	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else if (fd == -1)
		write(1, "Cannot read file.\n", 18);
	if (argc != 2 || fd == -1)
		return (1);
	while ((ret = read(fd, file, BUF_SIZE)))
		file[ret] = '\0';
	ft_putstr(file);
	close(fd);
	return (0);
}
