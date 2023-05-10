/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:20:12 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/10 16:14:25 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort(&list_a, &list_b);
	fake_ft_lstclear(&list_a);
	return (0);
}

/*ficheiro pronto*/