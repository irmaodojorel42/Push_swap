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

void    swap(t_list **list, char stack)
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

void    push(t_list **list1, t_list **list2, char stack)
{
    t_list  *reference;
    
    if (*list2 == NULL)
        return ;
    reference = *list2;
    *list2 = (*list2)->next;
    reference->next = *list1;
    *list1 = reference;
    if (stack == 'A')
        write(1, "pa\n", 3);
    if (stack == 'B')
        write(1, "pb\n", 3);
}

void    rotate(t_list **list, char stack)
{
    t_list *reference;
    t_list *reference2;

    reference = *list;
    reference2 = *list;
    while (reference->next != NULL)
        reference = reference->next;
    *list = (*list)->next;
    reference->next = reference2;
    reference2->next = NULL;
    if (stack == 'A')
        write(1, "ra\n", 3);
    if (stack == 'B')
        write(1, "rb\n", 3);
}

void    rev_rotate(t_list **list, char stack)
{
    t_list *reference;
    t_list *reference2;

    reference = *list;
    reference2 = *list;
    while (reference->next != NULL)
            reference = reference->next;
    while (reference2->next != reference)
            reference2 = reference2->next;
    reference->next = *list;
    *list = reference;
    reference2->next = NULL;
    if (stack == 'A')
        write(1, "rra\n", 3);
    if (stack == 'B')
        write(1, "rrb\n", 3);
}

void    dualmove(t_list **listA, t_list **listB, char move)
{
    if (move == 'S')
    {
        swap(listA, 'S');
        swap(listB, 'S');
        write(1, "ss\n", 3);
    }
    else if (move == 'r')
    {
        rotate(listA, 'r');
        rotate(listB, 'r');
        write(1, "rr\n", 3);
    }
    else if (move == 'R')
    {
        rev_rotate(listA, 'R');
        rev_rotate(listB, 'R');
        write(1, "rrr\n", 4);
    }
}