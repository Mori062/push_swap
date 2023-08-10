/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:01:57 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/10 12:03:18 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	tmp->prev = NULL;
	if (*stack_a == NULL)
		*stack_a = tmp;
	else
	{
		(*stack_a)->prev = tmp;
		while ((*stack_a)->prev != NULL)
			*stack_a = (*stack_a)->prev;
	}
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	tmp->prev = NULL;
	if (*stack_b == NULL)
		*stack_b = tmp;
	else
	{
		(*stack_b)->prev = tmp;
		while ((*stack_b)->prev != NULL)
			*stack_b = (*stack_b)->prev;
	}
	ft_putendl_fd("pb", 1);
}
