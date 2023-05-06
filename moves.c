/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:07:34 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/05 16:07:34 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **list, char stack)
{
	t_list	*reference;

	if (*list == NULL || (*list)->next == NULL)
		return (0);
	reference = *list;
	*list = (*list)->next;
	reference->next = (*list)->next;
	(*list)->next = reference;
	if (stack == 'A')
		write(1, "sa\n", 3);
	else if (stack == 'B')
		write(1, "sb\n", 3);
	return (1);
}

int	push(t_list **list1, t_list **list2, char stack)
{
	t_list	*reference;

	if (*list2 == NULL)
		return (0);
	reference = *list2;
	*list2 = (*list2)->next;
	reference->next = *list1;
	*list1 = reference;
	if (stack == 'A')
		write(1, "pa\n", 3);
	if (stack == 'B')
		write(1, "pb\n", 3);
	return (1);
}

int	rotate(t_list **list, char stack)
{
	t_list	*reference;
	t_list	*reference2;

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
	return (1);
}

int	rev_rotate(t_list **list, char stack)
{
	t_list	*reference;
	t_list	*reference2;

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
		write(1, "rra\n", 4);
	if (stack == 'B')
		write(1, "rrb\n", 4);
	return (1);
}

int	dualmove(t_list **listA, t_list **listB, char move)
{
	int	mv;

	mv = 0;
	if (move == 'S')
	{
		mv += swap(listA, 'S');
		mv += swap(listB, 'S');
		write(1, "ss\n", 3);
	}
	else if (move == 'r')
	{
		mv += rotate(listA, 'r');
		mv += rotate(listB, 'r');
		write(1, "rr\n", 3);
	}
	else if (move == 'R')
	{
		mv += rev_rotate(listA, 'R');
		mv += rev_rotate(listB, 'R');
		write(1, "rrr\n", 4);
	}
	return (mv);
}
