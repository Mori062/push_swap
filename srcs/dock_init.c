/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dock_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:13:19 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 14:09:33 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_init(t_stack **stack, int *args, size_t counter)
{
	t_stack	*tmp;
	size_t	i;

	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (*stack == NULL)
		return ;
	(*stack)->original = args[0];
	(*stack)->index = -1;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	tmp = *stack;
	i = 1;
	while (i < counter)
	{
		tmp->next = (t_stack *)malloc(sizeof(t_stack));
		if (tmp->next == NULL)
			return ;
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->original = args[i];
		tmp->index = -1;
		tmp->next = NULL;
		i++;
	}
}

t_dock	*dock_new(int *args, size_t counter)
{
	t_dock	*dock;

	dock = (t_dock *)malloc(sizeof(t_dock));
	if (dock == NULL)
		return (NULL);
	dock->stack_b = NULL;
	stack_init(&dock->stack_a, args, counter);
	return (dock);
}
