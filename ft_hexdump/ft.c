#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_printable(char c)
{
	if (c <= 31 || c == 127)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

int		ft_count_hex(int nb)
{
	int count;

	count = 1;
	if (nb < 16)
		return (count);
	count += ft_count_hex(nb / 16);
	return (count);
}

void	ft_puthex(int nb, int count)
{
	char	*hex;

	count++;
	hex = "0123456789abcdef";
	if (nb < 16)
	{
		if (count == 1)
			ft_putchar('0');
		ft_putchar(hex[nb]);
		return ;
	}
	ft_puthex(nb / 16, count);
	ft_putchar(hex[nb % 16]);
}
