/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:38:44 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/31 16:01:54 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		args_ckecker(int ac, char **av)
{
	int	i;
	int	j;
	int	sort_count;

	i = 1;
	sort_count = 0;
	while (i < ac)
	{
		j = 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				sort_count++;
			j++;
		}
		i++;
	}
	return (sort_count);
}


void	putargs2stack(int ac, char **av, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		stack_a->content = ft_atoi(av[i]);
		stack_a->index = i;
		stack_a->next = (t_stack *)malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
}
