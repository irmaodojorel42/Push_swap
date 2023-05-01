/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:14:16 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/01 23:32:10 by ceribeir         ###   ########.fr       */
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

void   ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst = new;
}