CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SOURCES = main.c
OBJECTS = ${SOURCES:.c=.o}

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
