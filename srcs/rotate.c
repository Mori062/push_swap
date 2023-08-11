/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:04:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 01:26:28 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack, size_t *rr_chance)
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
	if (rr_chance != NULL)
	{
		if (*rr_chance == 1)
			ft_putendl_fd("rr", 1);
		else
			ft_putendl_fd("ra", 1);
		*rr_chance = 0;
	}
	else
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack, size_t *rr_chance)
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
	if (rr_chance != NULL)
	{
		if (*rr_chance == 1)
			ft_putendl_fd("rb", 1);
		else
			*rr_chance = 1;
	}
	else
		ft_putendl_fd("rb", 1);
}

