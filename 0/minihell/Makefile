NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LDFLAGS = -L/opt/homebrew/opt/readline/lib
CPPFLAGS = -I/opt/homebrew/opt/readline/include
INCLUDE = include/
LIBFT = libft/libft.a
SRC = src/main.c \
	lexer/lexer.c \
	lexer/smart_split.c \
	exec/execute.c \
	util/free.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -lreadline $(LDFLAGS) $(OBJ) -o $(NAME) -Llibft -lft

%.o: %.c
	$(CC) $(CPPFLAGS) -I $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY : all clean fclean re
