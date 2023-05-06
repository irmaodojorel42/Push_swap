/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:57 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/06 16:50:47 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **list_a, t_list **list_b)
{
	t_list	*ref_1;
	t_list	*ref_2;
	t_list	*ref_3;

	ref_1 = *list_a;
	ref_2 = (*list_a)->next;
	ref_3 = ref_2->next;
	if (ft_lstsize(*list_a) == 2 && (*list_a)->nbr > ref_2->nbr)
		swap(list_a, 'A');
	if (ft_lstsize(*list_a) == 3)
		rule_3(ref_1, ref_2, ref_3, list_a);
	if (ft_lstsize(*list_a) == 5)
	{
		push(list_b, list_a, 'B');
		push(list_b, list_a, 'B');
		sort(list_a, list_b);
		rule_5(list_a, list_b);
		rule_5(list_a, list_b);
	}
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

void	rule_5(t_list **list_a, t_list **list_b)
{
	t_list	*reference;
	t_list	*next;
	t_list	*new;

	if ((*list_a)->nbr > (*list_b)->nbr)
		push(list_a, list_b, 'A');
	else if ((*list_a)->nbr < (*list_b)->nbr)
	{
		reference = *list_a;
		push(list_a, list_b, 'A');
		new = *list_a;
		while (reference->next != NULL)
			reference = reference->next;
		if (reference->nbr < new->nbr)
			rotate(list_a, 'A');
		else
		{
			*list_a = (*list_a)->next;
			reference = *list_a;
			next = reference->next;
			while (new->nbr > next->nbr)
			{
				reference = reference->next;
				next = reference->next;
			}
			new->next = next;
			reference->next = new;
		}
	}
}