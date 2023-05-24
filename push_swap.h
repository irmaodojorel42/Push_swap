/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:59 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/24 18:04:44 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/***********************LIBRARIES***********************/

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

/***********************STRUCT***********************/

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}					t_list;

/**********************FUNCTIONS_PUSH_SWAP*********************/

int			main(int ac, char **av);

/************************FUNCTIONS_LIST************************/

t_list		*ft_lstnew(int n);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		finish_list(t_list **list_a, t_list **list_b);

/*********************FUNCTIONS_VALID_ARGS*********************/

int			check(char *arg);
long long	converse(char *arg);
int			list_sort(t_list **list);
int			check_copy(t_list *lst, int n);

/************************FUNCTIONS_MOVES***********************/

void		swap(t_list **list, char stack);
void		rotate(t_list **list, char stack);
void		rev_rotate(t_list **list, char stack);
void		push(t_list **list1, t_list **list2, char stack);
void		dualmove(t_list **listA, t_list **listB, char move);

/*********************FUNCTIONS_FT_PRINTF*********************/

int			ft_putnbr(int n);
int			ft_putstr(char *s);
int			ft_putchar(char c);
int			ft_uint(unsigned int n);
int			ft_printf(const char *format, ...);
int			ft_formatype(char type, va_list args);
int			ft_check(unsigned long int n, int type);
int			ft_hexadec(unsigned long int n, int type);
void		print_stack(t_list **listA, t_list **listB);

/*********************FUNCTIONS_SORT*********************/

void		sort(t_list **list_a, t_list **list_b);
void		rule_5(t_list **list_a, t_list **list_b);
void		rule_100(t_list **list_a, t_list **list_b);
void		rule_500(t_list **list_a, t_list **list_b);
void		rule_3(int nbr_1, int nbr_2, int nbr_3, t_list **listA);

/*********************FUNCTIONS_INFO_LIST*********************/

int			maxi_nbr(t_list **list);
int			mini_nbr(t_list **list);
int			last_value(t_list **list);
int			distance(t_list **list, char nbr);
t_list		*copy_stack(t_list *list_a);

/*********************FUNCTIONS_MID_LIST*********************/

int			mid_nbr100(t_list **list_a);
int			mid_nbr500(t_list **list_a);
int			mid_b_nbr100(t_list **list_a);
int			mid_b_nbr500(t_list **list_a);

/*********************FUNCTIONS_FAKE_SORT*********************/

void		fake_swap(t_list **list);
void		fake_rotate(t_list **list);
void		fake_ft_lstclear(t_list **lst);
void		fake_rev_rotate(t_list **list);
void		fake_push(t_list **list1, t_list **list2);
void		fake_sort(t_list **list_a, t_list **list_b);
void		fake_rule_5(t_list **list_a, t_list **list_b);
void		fake_3(t_list *ref_1, t_list *ref_2, t_list *ref_3, t_list **listA);

#endif
