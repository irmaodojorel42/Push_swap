/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:17:00 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/01 23:50:52 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check(char *arg)
{
    int i;
    int ok;

    ok = 1;
    i = 0;
    while (arg[i])
    {
        if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ')
            i++;
        else
        {
            ok = 0;
            break ;
        }
    }
    return (ok);
}

int check_copy(t_list *lst)
{
    int ok;
    t_list *cmp;
    
    ok = 1;
    cmp = lst->next;
    while (cmp)
    {
        if (lst->nbr != cmp->nbr)
            cmp = cmp->next;
        else
        {
            ok = 0;
            break ;
        }
    }
    return (ok);
}

int	converse(char *arg)
{
	int	i;
	int	s;
	int	n;

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