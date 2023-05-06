/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:09:13 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/06 22:59:38 by ceribeir         ###   ########.fr       */
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

int	distance(t_list **list)
{
	t_list	*reference;
	int		mini;
	int		i;

	i = 1;
	mini = mini_nbr(list);
	reference = *list;
	while (reference->nbr != mini)
	{
		reference = reference->next;
		i++;
	}
	return (i);
}

int	mini_nbr_3(t_list **list)
{
	int		i;
	int		j;
	t_list	*reference;

	reference = *list;
	i = reference->nbr;
	j = 1;
	while (j != 3)
	{
		j++;
		reference = reference->next;
		if (reference->nbr < i)
			i = reference->nbr;
	}
	return (i);
}
