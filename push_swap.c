/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:20:12 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/02 16:17:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *list1;
    t_list  *list2;
    int i;
    
    i = 0;
    list1 = NULL;
    list2 = NULL;
    if (ac < 2)
        return (0);
    while (av[++i])
    {
        if (converse(av[i]) < -2147483648 || converse(av[i]) > 2147483647)
            ft_lstclear(&list1);
        else if (check(av[i]) > 0 && check_copy(list1, converse(av[i])) > 0)
            ft_lstadd_back(&list1, ft_lstnew(converse(av[i])));
        else
            ft_lstclear(&list1);
    }
    while (list1) 
    {
        printf("%d\n", list1->nbr);
        list1 = list1->next;
    }    
    return (0);
}