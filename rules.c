/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:57 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/09 14:55:37 by ceribeir         ###   ########.fr       */
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
	if (ft_lstsize(*list_a) >= 4 && ft_lstsize(*list_a) <= 10)
		rule_5(list_a, list_b);
	if (ft_lstsize(*list_a) > 10 && ft_lstsize(*list_a) <= 450)
		rule_100(list_a, list_b);
	if (ft_lstsize(*list_a) > 450)
		rule_500(list_a, list_b);
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
	while (ft_lstsize(*list_a) != 3)
	{
		if (distance(list_a, 'm') > (ft_lstsize(*list_a) / 2))
		{
			while (distance(list_a, 'm') != 1)
				rev_rotate(list_a, 'A');
		}
		else
		{
			while (distance(list_a, 'm') != 1)
				rotate(list_a, 'A');
		}
		push(list_b, list_a, 'B');
	}
	sort(list_a, list_b);
	while (ft_lstsize(*list_b) != 1)
	{
		while (distance(list_b, 'm') == 1)
			swap(list_b, 'B');
		push(list_a, list_b, 'A');
	}
	push(list_a, list_b, 'A');
}

void	rule_100(t_list **list_a, t_list **list_b)
{
	int		mid;
	int		mid_b;
	int		repit;

	repit = 0;
	while (repit++ != 3)
	{
		mid = mid_nbr100(list_a);
		mid_b = mid_b_nbr100(list_a);
		while (mini_nbr(list_a) <= mid)
		{
			if ((*list_a)->nbr <= mid)
			{
				push(list_b, list_a, 'B');
				if ((ft_lstsize(*list_b) > 1) && (repit <= 3))
				{
					if ((*list_b)->nbr < mid_b)
						rotate(list_b, 'B');
				}
			}
			else
				rotate(list_a, 'A');
		}
	}
	while (*list_b)
		push(list_a, list_b, 'A');
	rule_5(list_a, list_b);
}

void	rule_500(t_list **list_a, t_list **list_b)
{
	int		mid;
	int		mid_b;
	int		repit;

	repit = 0;
	while (repit != 28)
	{
		mid = mid_nbr500(list_a);
		mid_b = mid_b_nbr500(list_a);
		while (mini_nbr(list_a) <= mid)
		{
			if ((*list_a)->nbr <= mid)
			{
				push(list_b, list_a, 'B');
				if ((ft_lstsize(*list_b) > 1) && (repit <= 28))
				{
					if ((*list_b)->nbr < mid_b)
						rotate(list_b, 'B');
				}
			}
			else
				rotate(list_a, 'A');
		}
		repit++;
	}
	while (ft_lstsize(*list_a) > 0)
		push(list_b, list_a, 'B');
	// ft_printf("%d\n", ft_lstsize(*list_b));
	while (ft_lstsize(*list_b) > 0)
	{
		// ft_printf("ok\n");
		if (distance(list_b, 'M') > (ft_lstsize(*list_b) / 2))
		{
			while (distance(list_b, 'M') != 1)
				rev_rotate(list_b, 'B');
		}
		else
		{
			while (distance(list_b, 'M') != 1)
				rotate(list_b, 'B');
		}
		push(list_a, list_b, 'A');
	}
	//rule_5(list_a, list_b);
}
