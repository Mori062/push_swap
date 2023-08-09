/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:40:54 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/09 16:10:58 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
}

void	rrb(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
}

void	rrr(t_dock *dock)
{
	rra(&dock->stack_a);
	rrb(&dock->stack_b);
}
