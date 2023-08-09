/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:04:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/09 16:00:46 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = tmp;
	*stack = (*stack)->next;
	(*stack)->next = NULL;
}

void	rb(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = tmp;
	*stack = (*stack)->next;
	(*stack)->next = NULL;
}

void	rr(t_dock *dock)
{
	ra(&dock->stack_a);
	rb(&dock->stack_b);
}
