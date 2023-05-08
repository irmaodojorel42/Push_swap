# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 12:24:34 by ceribeir          #+#    #+#              #
#    Updated: 2023/05/07 23:35:46 by ceribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

RM = rm -f

AR = ar -rsc

SRC = push_swap.c list.c valid_args.c moves.c ft_typesprintf.c ft_printf.c rules.c info_list.c fakemoves.c fakesort.c

OBJ = $(SRC:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o push_swap

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONE: all clean fclan re

#-g3 -fsanitize=address