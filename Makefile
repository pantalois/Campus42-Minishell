LIBFT = libft/libft.a

LIBFT_MAKE = make --no-print-directory -C libft

NAME = minishell

SRC = test.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -lreadline

CC = cc

RM = rm -f

INCLUDE = minishell.h Makefile

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

all: library $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(READLINE)
				$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(READLINE) $(LFLAGS) -o $(NAME)


libft:
		$(LIBFT_MAKE)

clean:
				$(RM) $(OBJ)
				$(LIBFT_MAKE) clean

fclean: clean
				$(RM) $(NAME)
				$(LIBFT_MAKE) fclean

library:
				make -C libft

re: fclean all

.phony: all clean fclean re libft
