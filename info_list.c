/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:09:13 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/09 14:42:28 by ceribeir         ###   ########.fr       */
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
	int		mini;
	int		maxi;
	int		i;

	i = 1;
	mini = mini_nbr(list);
	maxi = maxi_nbr(list);
	reference = *list;
	if (nbr == 'M')
	{
		while (reference->nbr != maxi)
		{
			reference = reference->next;
			i++;
		}
	}
	if (nbr == 'm')
	{
		while (reference->nbr != mini)
		{
			reference = reference->next;
			i++;
		}
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

/*ficheiro cheio*/