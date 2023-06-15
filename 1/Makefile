NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
RM = rm -rf
LDFLAGS = -L/usr/local/opt/readline/lib
CFLAGS += -I/usr/local/opt/readline/include
INCLUDE = include/
LIBFT = libft/libft.a
SRC = src/main.c \
	src/env.c \
	lexer/lexer.c \
	lexer/split_to_list.c \
	lexer/split_metachar.c \
	lexer/parser.c \
	lexer/fill_in.c \
	lexer/join_cmd.c \
	exec/execute.c \
	exec/builtin_1.c \
	exec/builtin_2.c \
	util/free.c \
	util/lst_1.c \
	util/lst_2.c \
	util/util_1.c \
	util/util_2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(LDFLAGS) $(OBJ) -o $(NAME) -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

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
