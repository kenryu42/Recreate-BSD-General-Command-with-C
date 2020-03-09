#include <unistd.h>
#include "io.h"
#include "ft.h"
#include "ft_2.h"

void	print_padding(int i, int option_C)
{
	int padding;

	if (option_C)
		padding = (i < 7) ? (16 - i) * 3 + 2 : (16 - i) * 3 + 1;
	else
		padding = (16 - i) * 3 - 1;
	while (padding--)
		write(1, " ", 1);
	if (!option_C)
		write(1, "\n", 1);
}

void	print_contents(char *file, int index)
{
	int i;

	i = 0;
	write(1, "|", 1);
	while (i < 16 && file[index])
	{
		ft_put_printable(file[index++]);
		i++;
	}
	write(1, "|\n", 2);
}

void	print_hexdump_option(char *file)
{
	int i;
	int index;
	int line_nb;

	index = 0;
	line_nb = 0;
    while (file[index])
    {
        i = 0;
        print_hexline(line_nb++, 1);
        while (i < 16 && file[index])
        {
            ft_puthex(file[index++], 0);
            if (i == 7 || i == 15)
                write (1, "  ", 2);
			else
				write(1, " ", 1);
            i++;
        }
			if (i < 16)
				print_padding(i, 1);
			print_contents(file, index - i);
    }
    print_total_hex(index, 1);
}
