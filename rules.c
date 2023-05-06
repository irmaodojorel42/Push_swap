/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:57 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/07 00:03:09 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_list **list_a, t_list **list_b)
{
	t_list	*ref_1;
	t_list	*ref_2;
	t_list	*ref_3;
	int		mv;

	mv = 0;
	ref_1 = *list_a;
	ref_2 = (*list_a)->next;
	ref_3 = ref_2->next;
	if (ft_lstsize(*list_a) == 2 && (*list_a)->nbr > ref_2->nbr)
		mv += swap(list_a, 'A');
	if (ft_lstsize(*list_a) == 3)
		mv += rule_3(ref_1, ref_2, ref_3, list_a);
	if (ft_lstsize(*list_a) >= 4 && ft_lstsize(*list_a) <= 10)
		mv += rule_5(list_a, list_b);
	if (ft_lstsize(*list_a) > 10)
		mv += rule_100(list_a, list_b);
	return (mv);
}

int	rule_3(t_list *ref_1, t_list *ref_2, t_list *ref_3, t_list **listA)
{
	static int	mv;

	if (ref_1->nbr > ref_2->nbr)
	{
		if (ref_3->nbr > ref_2->nbr && ref_3->nbr > ref_1->nbr)
			mv += swap(listA, 'A');
		else if (ref_3->nbr > ref_2->nbr && ref_1->nbr > ref_3->nbr)
			mv += rotate(listA, 'A');
		else if (ref_2->nbr > ref_3->nbr && ref_1->nbr > ref_3->nbr)
		{
			mv += swap(listA, 'A');
			mv += rev_rotate(listA, 'A');
		}
	}
	else if (ref_2->nbr > ref_1->nbr)
	{
		if (ref_2->nbr > ref_3->nbr && ref_1->nbr > ref_3->nbr)
			mv += rev_rotate(listA, 'A');
		else if (ref_2->nbr > ref_3->nbr && ref_3->nbr > ref_1->nbr)
		{
			mv += swap(listA, 'A');
			mv += rotate(listA, 'A');
		}
	}
	return (mv);
}

int	rule_5(t_list **list_a, t_list **list_b)
{
	static int		mv;

	while (ft_lstsize(*list_a) != 3)
	{
		if (distance(list_a) > 3)
		{
			while (distance(list_a) != 1)
				mv += rev_rotate(list_a, 'A');
		}
		else
		{
			while (distance(list_a) != 1)
				mv += rotate(list_a, 'A');
		}
		mv += push(list_b, list_a, 'B');
	}
	mv += sort(list_a, list_b);
	while (ft_lstsize(*list_b) != 1)
	{
		while (distance(list_b) == 1)
			mv += swap(list_b, 'B');
		mv += push(list_a, list_b, 'A');
	}
	mv += push(list_a, list_b, 'A');
	return (mv);
}

int	rule_100(t_list **list_a, t_list **list_b)
{
	int		mv;
	t_list	*ref_1;
	t_list	*ref_2;
	t_list	*ref_3;

	mv = 0;
	while (ft_lstsize(*list_a) > 4)
	{
		ref_1 = *list_a;
		ref_2 = (*list_a)->next;
		ref_3 = ref_2->next;
		mv += rule_3(ref_1, ref_2, ref_3, list_a);
		mv += push(list_b, list_a, 'B');
		mv += push(list_b, list_a, 'B');
		mv += push(list_b, list_a, 'B');
	}
	mv += rule_3(ref_1, ref_2, ref_3, list_a);
	while (ft_lstsize(*list_b) != 0)
	{
		if ((*list_a)->nbr > mini_nbr_3(list_b))
		{
			mv += push(list_a, list_b, 'A');
			mv += push(list_a, list_b, 'A');
			mv += push(list_a, list_b, 'A');
		}
		else
		{
			mv += push(list_a, list_b, 'A');
			mv += push(list_a, list_b, 'A');
			mv += push(list_a, list_b, 'A');
			mv += rotate(list_a, 'A');
			mv += rotate(list_a, 'A');
			mv += rotate(list_a, 'A');
		}
	}
	rule_5(list_a, list_b);
	return (mv);
}
