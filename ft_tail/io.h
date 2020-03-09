#ifndef IO_H
# define IO_H

void	ft_puttail(char *str, int tail);
void	ft_put_byte_tail(char *str, int tail, int byte);
void	tail_std_input(char *file, int byte);
int		tail_files(int argc, char **argv, char *file, int byte);
void	helper(int fd, char *file, int byte);

#endif
