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

void    sa(t_list **listA)
{
    t_list  *referenceA;

    if (*listA == NULL || (*listA)->next == NULL)
        return ;
    referenceA = *listA;
    *listA = (*listA)->next;
    referenceA->next = (*listA)->next;
    (*listA)->next = referenceA;
}

void    sb(t_list **listB)
{
    t_list  *referenceB;

    if (*listB == NULL || (*listB)->next == NULL)
        return ;
    referenceB = *listB;
    *listB = (*listB)->next;
    referenceB->next = (*listB)->next;
    (*listB)->next = referenceB;
}

void    ss(t_list *listA, t_list *listB)
{
    sa(&listA);
    sb(&listB);
}

void    pa(t_list **listA, t_list **listB)
{
    t_list  *referenceB;
    
    if (*listB == NULL)
        return ;
    referenceB = *listB;
    *listB = (*listB)->next;
    referenceB->next = *listA
    *listA = referenceB;
}

