/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fakemoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:14:32 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/10 14:57:00 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fake_swap(t_list **list)
{
	t_list	*reference;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	reference = *list;
	*list = (*list)->next;
	reference->next = (*list)->next;
	(*list)->next = reference;
}

void	fake_push(t_list **list1, t_list **list2)
{
	t_list	*reference;

	if (*list2 == NULL)
		return ;
	reference = *list2;
	*list2 = (*list2)->next;
	reference->next = *list1;
	*list1 = reference;
}

void	fake_rotate(t_list **list)
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
}

void	fake_rev_rotate(t_list **list)
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
}

/*ficheiro pronto*/
