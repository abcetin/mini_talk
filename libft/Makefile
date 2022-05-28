NAME	:= libft.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -I.

FILES	:= $(shell find . -type f ! -name "ft_lst*.c" -name "ft_*.c")
OBJS	:= $(FILES:%.c=%.o)
BONUS	:= $(wildcard *.c)
BOBJS	:= $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

bonus: $(BOBJS)
	@ar -rcs $(NAME) $(BOBJS)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
