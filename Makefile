# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 12:24:34 by ceribeir          #+#    #+#              #
#    Updated: 2023/05/25 12:36:27 by ceribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

RM = rm -f

AR = ar -rsc

SRC =	01_push_swap.c 02_valid_args.c 03_list.c 04_sort.c 05_moves.c \
		06_info_list.c 07_mid_list.c 08_fake_sort.c 09_fake_moves.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o push_swap
	@echo "compile... done!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "remove obj... done!"
	$(RM) $(OBJ)

fclean: clean
	@echo "remove push_swap... done!"
	$(RM) $(NAME)
	
re: fclean all
	
.PHONE: all clean fclan re