/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:07:18 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/10 15:31:37 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int n)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*reference;

	reference = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (reference->next != NULL)
			reference = reference->next;
		reference->next = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*reference;

	if (!*lst)
		exit (write(1, "Error\n", 6));
	while (*lst)
	{
		reference = (*lst)->next;
		free (*lst);
		*lst = reference;
	}
	lst = NULL;
	exit (write(1, "Error\n", 6));
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	finish_list(t_list **list_a, t_list **list_b)
{
	while (ft_lstsize(*list_a) > 0)
		push(list_b, list_a, 'B');
	while (ft_lstsize(*list_b) > 0)
	{
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
}

/*ficheiro cheio*/