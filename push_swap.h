/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:59 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/05 22:32:15 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/***********************LIBRARIES***********************/

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/***********************STRUCT***********************/

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}					t_list;

/**********************FUNCTIONS_PUSH_SWAP*********************/

int		main(int ac, char **av);
void	print_stack(t_list **listA, t_list **listB);

/************************FUNCTIONS_LIST************************/

t_list	*ft_lstnew(int n);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*********************FUNCTIONS_VALID_ARGS*********************/

int		check(char *arg);
long int	converse(char *arg);
int		check_copy(t_list *lst, int n);

/************************FUNCTIONS_MOVES***********************/

void	swap(t_list **list, char stack);
void	rotate(t_list **list, char stack);
void	rev_rotate(t_list **list, char stack);
void	push(t_list **list1, t_list **list2, char stack);
void	dualmove(t_list **listA, t_list **listB, char move);

/*********************FUNCTIONS_FT_PRINTF*********************/

int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_uint(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_formatype(char type, va_list args);
int		ft_check(unsigned long int n, int type);
int		ft_hexadec(unsigned long int n, int type);

/*********************FUNCTIONS_RULES*********************/

void	sort(t_list **list_a, t_list **list_b);
void	rule_5(t_list **list_a, t_list **list_b);
void	rule_3(t_list *ref_1, t_list *ref_2, t_list *ref_3, t_list **listA);

#endif
