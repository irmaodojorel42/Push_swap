/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:09:13 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/10 16:14:12 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mini_nbr(t_list **list)
{
	int		i;
	t_list	*reference;

	reference = *list;
	i = reference->nbr;
	while (reference->next != NULL)
	{
		reference = reference->next;
		if (reference->nbr < i)
			i = reference->nbr;
	}
	return (i);
}

int	maxi_nbr(t_list **list)
{
	int		i;
	t_list	*reference;

	reference = *list;
	i = reference->nbr;
	while (reference->next != NULL)
	{
		reference = reference->next;
		if (reference->nbr > i)
			i = reference->nbr;
	}
	return (i);
}

t_list	*copy_stack(t_list *list_a)
{
	t_list	*copy;
	t_list	*ref_copy;

	ref_copy = NULL;
	if (list_a)
	{
		copy = ft_lstnew(list_a->nbr);
		ref_copy = copy;
		list_a = list_a->next;
		while (list_a)
		{
			copy->next = ft_lstnew(list_a->nbr);
			copy = copy->next;
			list_a = list_a->next;
		}
	}
	return (ref_copy);
}

int	distance(t_list **list, char nbr)
{
	t_list	*reference;
	int		value;
	int		i;

	i = 1;
	reference = *list;
	if (nbr == 'M')
		value = maxi_nbr(list);
	if (nbr == 'm')
		value = mini_nbr(list);
	while (reference->nbr != value)
	{
		reference = reference->next;
		i++;
	}
	return (i);
}

int	last_value(t_list **list)
{
	t_list	*reference;
	int		value;
	
	reference = *list;
	while (reference->next != NULL)
		reference = reference->next;
	value = reference->nbr;
	return (value);
}

/*ficheiro cheio*/