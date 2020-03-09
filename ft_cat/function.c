#include <unistd.h>

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

void	ft_put_stderr(char *str, char *path_name)
{
	write(2, "ft_cat: ", 8);
	while (*path_name)
		write(2, path_name++, 1);
	write(2, ": ", 2);
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
}
