# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 12:24:34 by ceribeir          #+#    #+#              #
#    Updated: 2023/05/05 18:31:21 by ceribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

AR = ar -rsc

SRC = push_swap.c list.c valid_args.c moves.c ft_typesprintf.c ft_printf.c rules.c

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