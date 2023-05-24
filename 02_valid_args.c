/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:17:00 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/24 18:04:05 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sort(t_list **list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *list;
	next = (*list)->next;
	while (next)
	{
		if (tmp->nbr > next->nbr)
			return (1);
		tmp = tmp->next;
		next = next->next;
	}
	exit (0);
}

int	check(char *arg)
{
	int	i;
	int	ok;

	ok = 0;
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		ok = 1;
		if ((arg[i] >= '0' && arg[i] <= '9'))
			i++;
		else
		{
			ok = 0;
			break ;
		}
	}
	return (ok);
}

int	check_copy(t_list *lst, int n)
{
	int		ok;
	t_list	*cmp;

	ok = 1;
	cmp = lst;
	while (cmp)
	{
		if (cmp->nbr != n)
			cmp = cmp->next;
		else
		{
			ok = 0;
			break ;
		}
	}
	return (ok);
}

long long	converse(char *arg)
{
	int			i;
	int			s;
	long long	n;

	i = 0;
	s = 1;
	n = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			s *= -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		n *= 10;
		n += arg[i++] - '0';
	}
	return (n * s);
}

/*ficheiro pronto*/