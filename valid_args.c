/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:17:00 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/03 23:21:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int check(char *arg)
{
    int i;
    int ok;

    ok = 0;
    i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    while (arg[i])
    {
        if ((arg[i] >= '0' && arg[i++] <= '9'))
            ok = 1;
        else
        {
            ok = 0;
            break ;
        }
    }
    return (ok);
}

int check_copy(t_list *lst, int n)
{
    int ok;
    t_list *cmp;
    
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

long int	converse(char *arg)
{
	int	i;
	int	s;
	long int	n;

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