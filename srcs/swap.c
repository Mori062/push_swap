/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:25 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 14:12:33 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack, size_t *rr_chance)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->prev = *stack;
	(*stack)->prev = NULL;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	if (rr_chance != NULL)
	{
		if (*rr_chance == 1)
			ft_putendl_fd("rb", 1);
		*rr_chance = 0;
	}
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack, size_t *rr_chance)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->prev = *stack;
	(*stack)->prev = NULL;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	if (rr_chance != NULL)
	{
		if (*rr_chance == 1)
			ft_putendl_fd("rb", 1);
		*rr_chance = 0;
	}
	ft_putendl_fd("sb", 1);
}
