/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:59 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/04 00:05:33 by marvin           ###   ########.fr       */
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

int     push(int ac, char **av);
t_list   *ft_lstnew(int n);
void   ft_lstadd_back(t_list **lst, t_list *new);
long int converse(char *arg);
int check(char *arg);
int check_copy(t_list *lst, int n);
void    ft_lstclear(t_list **lst);
void    sa(t_list **listA);
void    pa(t_list **listA, t_list **listB);

#endif