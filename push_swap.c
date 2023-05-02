/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:20:12 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/04 00:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *listA;
    t_list  *listB;
    int i;
    
    i = 0;
    listA = NULL;
    listB = ft_lstnew(1);
    if (ac < 2)
        return (0);
    while (av[++i])
    {
        if (converse(av[i]) < -2147483648 || converse(av[i]) > 2147483647)
            ft_lstclear(&listA);
        else if (check(av[i]) > 0 && check_copy(listA, converse(av[i])) > 0)
            ft_lstadd_back(&listA, ft_lstnew(converse(av[i])));
        else
            ft_lstclear(&listA);
    }
    pa(&listA, &listB);
    while (listA) 
    {
        printf("%d\n", listA->nbr);
        listA = listA->next;
    }
    return (0);
}