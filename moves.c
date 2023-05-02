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
    t_list  *referenceA = *listA;
    t_list  *next = (*listA)->next;

    if (*listA != NULL || (*listA)->next != NULL)
    {
        referenceA->next = next->next;
        next->next = referenceA;
        *listA = next;
        (*listA)->next = referenceA->next;
    }
    return ;
}