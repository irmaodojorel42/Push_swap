/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fakesort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:14:16 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/09 14:23:08 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fake_sort(t_list **list_a, t_list **list_b)
{
	t_list	*ref_1;
	t_list	*ref_2;
	t_list	*ref_3;

	ref_1 = *list_a;
	ref_2 = (*list_a)->next;
	ref_3 = ref_2->next;
	if (ft_lstsize(*list_a) == 2 && (*list_a)->nbr > ref_2->nbr)
		fake_swap(list_a);
	if (ft_lstsize(*list_a) == 3)
		fake_3(ref_1, ref_2, ref_3, list_a);
	if (ft_lstsize(*list_a) >= 4)
		fake_rule_5(list_a, list_b);
}

void	fake_3(t_list *ref_1, t_list *ref_2, t_list *ref_3, t_list **listA)
{
	if (ref_1->nbr > ref_2->nbr)
	{
		if (ref_3->nbr > ref_2->nbr && ref_3->nbr > ref_1->nbr)
			fake_swap(listA);
		else if (ref_3->nbr > ref_2->nbr && ref_1->nbr > ref_3->nbr)
			fake_rotate(listA);
		else if (ref_2->nbr > ref_3->nbr && ref_1->nbr > ref_3->nbr)
		{
			fake_swap(listA);
			fake_rev_rotate(listA);
		}
	}
	else if (ref_2->nbr > ref_1->nbr)
	{
		if (ref_2->nbr > ref_3->nbr && ref_1->nbr > ref_3->nbr)
			fake_rev_rotate(listA);
		else if (ref_2->nbr > ref_3->nbr && ref_3->nbr > ref_1->nbr)
		{
			fake_swap(listA);
			fake_rotate(listA);
		}
	}
}

void	fake_rule_5(t_list **list_a, t_list **list_b)
{
	while (ft_lstsize(*list_a) != 3)
	{
		if (distance(list_a, 'm') > (ft_lstsize(*list_a) / 2))
		{
			while (distance(list_a, 'm') != 1)
				fake_rev_rotate(list_a);
		}
		else
		{
			while (distance(list_a, 'm') != 1)
				fake_rotate(list_a);
		}
		fake_push(list_b, list_a);
	}
	fake_sort(list_a, list_b);
	while (ft_lstsize(*list_b) != 1)
	{
		while (distance(list_b, 'm') == 1)
			fake_swap(list_b);
		fake_push(list_a, list_b);
	}
	fake_push(list_a, list_b);
}

void	fake_ft_lstclear(t_list **lst)
{
	t_list	*reference;

	if (!*lst)
		return ;
	while (*lst)
	{
		reference = (*lst)->next;
		free (*lst);
		*lst = reference;
	}
	lst = NULL;
}

