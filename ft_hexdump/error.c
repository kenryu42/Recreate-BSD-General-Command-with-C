#include <unistd.h>

void	print_error_message(char *file, char *error, int err_no, int last)
{
	int i;
	
	i = 0;
	write(2, "ft_hexdump: ", 12);
	while (file[i])
		write(2, &file[i++], 1);
	write(2, ": ", 2);
	while (*error)
		write(2, error++, 1);
	write(2, "\n", 1);
	if (err_no == 2 && last)
	{
		write(2, "ft_hexdump: ", 12);
		while (*file)
			write(2, file++, 1);
		write(2, ": Bad file descriptor\n", 22);
	}
}
