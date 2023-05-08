/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:09:13 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/08 15:43:43 by ceribeir         ###   ########.fr       */
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

int	mid_nbr(t_list **list_a)
{
	int		i;
	t_list	*reference_a;
	t_list	*reference_b;

	i = (ft_lstsize(*list_a) / 2);
	reference_a = copy_stack(*list_a);
	reference_b = NULL;
	fake_sort(&reference_a, &reference_b);
	while (i != 1)
	{
		reference_a = reference_a->next;
		i--;
	}
	i = reference_a->nbr;
	fake_ft_lstclear(&reference_a);
	//ft_printf("mid: %d", i);
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

int	mini_nbr_next(t_list **list)
{
	int		mini;
	int		next;
	t_list	*reference;

	mini = mini_nbr(list);
	reference = *list;
	if (reference->nbr != mini)
		next = reference->nbr;
	else
	{
		reference = reference->next;
		next = reference->nbr;
	}
	while (reference->next != NULL)
	{
		reference = reference->next;
		if ((reference->nbr < next) && (reference->nbr != mini))
			next = reference->nbr;
	}
	return (next);
}

/*ficheiro cheio*/