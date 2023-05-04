/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:59:09 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 19:59:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sasb(t_list **list, char stack)
{
    t_list  *reference;

    if (*list == NULL || (*list)->next == NULL)
        return ;
    reference = *list;
    *list = (*list)->next;
    reference->next = (*list)->next;
    (*list)->next = reference;
    if (stack == 'A')
        write(1, "sa\n", 3);
    else if (stack == 'B')
        write(1, "sb\n", 3);
}

void    ss(t_list **listA, t_list **listB)
{
    sasb(listA, 'X');
    sasb(listB, 'X');
    write(1, "ss\n", 3);
}

void    pa(t_list **listA, t_list **listB)
{
    t_list  *referenceB;
    
    if (*listB == NULL)
        return ;
    referenceB = *listB;
    *listB = (*listB)->next;
    referenceB->next = *listA;
    *listA = referenceB;
    write(1, "pa\n", 3);
}