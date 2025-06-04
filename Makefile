NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	get_next_line_utils.c \
		get_next_line.c \


OBJ = $(SRC:.c=.o)
B_OBJ = $(BONUS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus: $(B_OBJ)
	make
	@ar rcs $(NAME) $(B_OBJ)

.PHONY: all bonus clean fclean re
