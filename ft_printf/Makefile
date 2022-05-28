# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acetin <acetin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:43:28 by acetin            #+#    #+#              #
#    Updated: 2022/03/02 12:19:11 by acetin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.


SRC	= $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

bonus: all

.PHONY:	all clean fclean re bonus
