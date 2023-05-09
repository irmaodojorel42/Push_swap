/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:20:12 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/09 13:48:09 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **list_1, t_list **list_2)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *list_1;
	list_b = *list_2;
	ft_printf("Stack A | Stack B\n");
	while (list_a || list_b)
	{
		if (list_a)
		{
			ft_printf("%d       | ", list_a->nbr);
			list_a = list_a->next;
		}
		else
			ft_printf("        | ");
		if (list_b)
		{
			ft_printf("%d\n", list_b->nbr);
			list_b = list_b->next;
		}
		else
			ft_printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int		i;

	i = 0;
	list_a = NULL;
	list_b = NULL;
	if (ac < 2)
		return (0);
	while (av[++i])
	{
		if (converse(av[i]) < -2147483648 || converse(av[i]) > 2147483647)
			ft_lstclear(&list_a);
		else if (check(av[i]) > 0 && check_copy(list_a, converse(av[i])) > 0)
			ft_lstadd_back(&list_a, ft_lstnew(converse(av[i])));
		else
			ft_lstclear(&list_a);
	}
	//print_stack(&list_a, &list_b);
	sort(&list_a, &list_b);
	//print_stack(&list_a, &list_b);
	fake_ft_lstclear(&list_a);
	return (0);
}
