/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:40:54 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/10 12:48:48 by morishitash      ###   ########.fr       */
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
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->prev->next = NULL;
	tmp->prev = NULL;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->prev->next = NULL;
	tmp->prev = NULL;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_dock *dock)
{
	rra(&dock->stack_a);
	rrb(&dock->stack_b);
}
