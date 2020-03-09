#ifndef IO_H
# define IO_H

void	print_hexline(int nb, int option_C);
void	print_total_hex(int total, int option_C);
void	print_hexdump(char *file);
void	hexdump_stdi(char *file, char *line, int option_C);
void	hexdump_files(int argc, char **argv, char *file, int option_C);

#endif
