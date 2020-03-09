#include <unistd.h>
#include "error.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	if ((!*s1 && !*s2) || (*s1 != *s2))
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}

void	print_file_name(char *file_name)
{
	write(1, "==> ", 4);
    while (*file_name)
        write(1, file_name++, 1);
    write(1, " <==\n", 5);
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

int		ft_atoi(char *str)
{
	int result;

	result = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	return (result);
}
