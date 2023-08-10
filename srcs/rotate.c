/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:04:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/11 00:41:22 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	tmp->prev = (*stack);
	(*stack)->next = tmp;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	tmp->prev = (*stack);
	(*stack)->next = tmp;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	ft_putendl_fd("rb", 1);
}

void	rr(t_dock *dock)
{
	ra(&dock->stack_a);
	rb(&dock->stack_b);
}
