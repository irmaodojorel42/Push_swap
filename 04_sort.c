/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:57 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/24 18:20:48 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **list_a, t_list **list_b)
{
	int	nbr_1;
	int	nbr_2;
	int	nbr_3;

	nbr_1 = (*list_a)->nbr;
	nbr_2 = (*list_a)->next->nbr;
	if (ft_lstsize(*list_a) == 2)
		swap(list_a, 'A');
	else if (ft_lstsize(*list_a) == 3)
	{
		nbr_3 = (*list_a)->next->next->nbr;
		rule_3(nbr_1, nbr_2, nbr_3, list_a);
	}
	else if (ft_lstsize(*list_a) >= 4 && ft_lstsize(*list_a) <= 50)
		rule_5(list_a, list_b);
	else if (ft_lstsize(*list_a) > 50 && ft_lstsize(*list_a) <= 300)
		rule_100(list_a, list_b);
	else if (ft_lstsize(*list_a) > 300)
		rule_500(list_a, list_b);
}

void	rule_3(int nbr_1, int nbr_2, int nbr_3, t_list **listA)
{
	if (nbr_1 > nbr_2)
	{
		if (nbr_3 > nbr_2 && nbr_3 > nbr_1)
			swap(listA, 'A');
		else if (nbr_3 > nbr_2 && nbr_1 > nbr_3)
			rotate(listA, 'A');
		else if (nbr_2 > nbr_3 && nbr_1 > nbr_3)
		{
			swap(listA, 'A');
			rev_rotate(listA, 'A');
		}
	}
	else if (nbr_2 > nbr_1)
	{
		if (nbr_2 > nbr_3 && nbr_1 > nbr_3)
			rev_rotate(listA, 'A');
		else if (nbr_2 > nbr_3 && nbr_3 > nbr_1)
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
	while (repit++ != 5)
	{
		mid = mid_nbr100(list_a);
		mid_b = mid_b_nbr100(list_a);
		while (mini_nbr(list_a) <= mid)
		{
			if ((*list_a)->nbr <= mid)
			{
				push(list_b, list_a, 'B');
				if ((ft_lstsize(*list_b) > 1) && (repit <= 5))
				{
					if ((*list_b)->nbr < mid_b && (*list_a)->nbr > mid)
						dualmove(list_a, list_b, 'r');
					else if ((*list_b)->nbr < mid_b)
						rotate(list_b, 'B');
				}
			}
			else
				rotate(list_a, 'A');
		}
	}
	finish_list(list_a, list_b);
}

void	rule_500(t_list **list_a, t_list **list_b)
{
	int		mid;
	int		mid_b;
	int		repit;

	repit = 0;
	while (repit++ != 8)
	{
		mid = mid_nbr500(list_a);
		mid_b = mid_b_nbr500(list_a);
		while (mini_nbr(list_a) <= mid)
		{
			if ((*list_a)->nbr <= mid)
			{
				push(list_b, list_a, 'B');
				if ((ft_lstsize(*list_b) > 1) && (repit <= 8))
				{
					if ((*list_b)->nbr < mid_b && (*list_a)->nbr > mid)
						dualmove(list_a, list_b, 'r');
					else if ((*list_b)->nbr < mid_b)
						rotate(list_b, 'B');
				}
			}	
			else
				rotate(list_a, 'A');
		}
	}
	rule_100(list_a, list_b);
}

/*ficheiro pronto*/