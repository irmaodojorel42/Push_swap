/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:59 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/04 13:13:10 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}					t_list;

/****************FUNCTIONS_PUSH_SWAP****************/

int		main(int ac, char **av);
void    print_stack(t_list **listA, t_list **listB);

/****************FUNCTIONS_LIST****************/

t_list	*ft_lstnew(int n);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/****************FUNCTIONS_VALID_ARGS****************/

int		check(char *arg);
long int	converse(char *arg);
int		check_copy(t_list *lst, int n);

/****************FUNCTIONS_MOVES****************/

void    swap(t_list **list, char stack);
void    rotate(t_list **list, char stack);
void    rev_rotate(t_list **list, char stack);
void    push(t_list **list1, t_list **list2, char stack);
void    dualmove(t_list **listA, t_list **listB, char move);

#endif