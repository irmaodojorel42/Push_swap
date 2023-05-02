/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:14:16 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/02 20:05:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list   *ft_lstnew(int n)
{
    t_list  *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->nbr = n;
    new->next = NULL;
    return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*reference;

	reference = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (reference->next != NULL)
			reference = reference->next;
		reference->next = new;
	}
}

void    ft_lstclear(t_list **lst)
{
    t_list  *reference;

    if (!*lst)
        exit (write(1, "Error\n", 6));
    while (*lst)
    {
        reference = (*lst)->next;
        free (*lst);
        *lst = reference;
    }
    lst = NULL;
    exit (write(1, "Error\n", 6));
}