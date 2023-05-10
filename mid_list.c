/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:03:46 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/10 18:56:18 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mid_nbr100(t_list **list_a)
{
	int		i;
	t_list	*reference_a;
	t_list	*reference_b;

	i = (ft_lstsize(*list_a) / 2);
	reference_a = copy_stack(*list_a);
	reference_b = NULL;
	fake_sort(&reference_a, &reference_b);
	reference_b = reference_a;
	while (i-- != 1)
		reference_a = reference_a->next;
	i = reference_a->nbr;
	fake_ft_lstclear(&reference_b);
	return (i);
}

int	mid_b_nbr100(t_list **list_a)
{
	int		i;
	int		j;
	t_list	*reference_a;
	t_list	*reference_b;
	t_list	*reference_sort;

	i = (ft_lstsize(*list_a) / 2);
	j = (i / 2);
	reference_a = copy_stack(*list_a);
	reference_b = NULL;
	fake_sort(&reference_a, &reference_b);
	reference_sort = reference_a;
	reference_b = reference_a;
	while (i-- != 1)
		reference_a = reference_a->next;
	while (j-- != 1)
		reference_sort = reference_sort->next;
	i = reference_sort->nbr;
	fake_ft_lstclear(&reference_b);
	return (i);
}

int	mid_nbr500(t_list **list_a)
{
	int		i;
	t_list	*reference_a;
	t_list	*reference_b;

	i = (ft_lstsize(*list_a) / 5);
	reference_a = copy_stack(*list_a);
	reference_b = NULL;
	fake_sort(&reference_a, &reference_b);
	reference_b = reference_a;
	while (i-- != 1)
		reference_a = reference_a->next;
	i = reference_a->nbr;
	fake_ft_lstclear(&reference_b);
	return (i);
}

int	mid_b_nbr500(t_list **list_a)
{
	int		i;
	int		j;
	t_list	*reference_a;
	t_list	*reference_b;
	t_list	*reference_sort;

	i = (ft_lstsize(*list_a) / 5);
	j = (i / 2);
	reference_a = copy_stack(*list_a);
	reference_b = NULL;
	fake_sort(&reference_a, &reference_b);
	reference_sort = reference_a;
	reference_b = reference_a;
	while (i-- != 1)
		reference_a = reference_a->next;
	while (j-- != 1)
		reference_sort = reference_sort->next;
	i = reference_sort->nbr;
	fake_ft_lstclear(&reference_b);
	return (i);
}

/*ficheiro cheio*/