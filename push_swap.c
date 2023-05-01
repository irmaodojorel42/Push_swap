/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceribeir <ceribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:20:12 by ceribeir          #+#    #+#             */
/*   Updated: 2023/05/01 23:52:09 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *list1;
    t_list  *list2;
    t_list  *reference;
    int i;
    
    i = 0;
    list1 = NULL;
    list2 = NULL;
    reference = list1;
    if (ac < 2)
        return (0);
    while (av[++i])
    {
        if (check(av[i]) > 0)
        {
            ft_lstadd_front(&list1, ft_lstnew(converse(av[i])));
            if (check_copy(list1) == 0)
            {
                write(1, "Error\n", 6);
                return (0);
            }
        }
        else
        {
            write(1, "Error\n", 6);
            return (0);
        }
    }
    while (list1) 
    {
        printf("%d\n", list1->nbr);
        list1 = list1->next;
    }    
    return (0);
}