/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:25 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/09 15:51:57 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	ft_putendl_fd("sb", 1);
}

void	ss(t_dock *dock)
{
	sa(&dock->stack_a);
	sb(&dock->stack_b);
}
