/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:57 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/05 21:41:50 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **listA)
{
	t_list	*ref_1;
	t_list	*ref_2;
	t_list	*ref_3;

	ref_1 = *listA;
	ref_2 = (*listA)->next;
	ref_3 = ref_2->next;
	if (ft_lstsize(*listA) == 3)
		rule_3(ref_1, ref_2, ref_3, listA);
}

void	rule_3(t_list *ref_1, t_list *ref_2, t_list *ref_3, t_list **listA)
{
	if (ref_1->nbr > ref_2->nbr)
	{
		if (ref_3->nbr > ref_2->nbr && ref_3->nbr > ref_1->nbr)
			swap(listA, 'A');
		else if (ref_3->nbr > ref_2->nbr && ref_1->nbr > ref_3->nbr)
			rotate(listA, 'A');
		else if (ref_2->nbr > ref_3->nbr && ref_1->nbr > ref_3->nbr)
		{
			swap(listA, 'A');
			rev_rotate(listA, 'A');
		}
	}
	else if (ref_2->nbr > ref_1->nbr)
	{
		if (ref_2->nbr > ref_3->nbr && ref_1->nbr > ref_3->nbr)
			rev_rotate(listA, 'A');
		else if (ref_2->nbr > ref_3->nbr && ref_3->nbr > ref_1->nbr)
		{
			swap(listA, 'A');
			rotate(listA, 'A');
		}
	}
}
