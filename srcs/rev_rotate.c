/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:40:54 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 01:00:53 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack, size_t *rr_chance)
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
	if (rr_chance != NULL)
	{
		if (*rr_chance == 1)
			ft_putendl_fd("rb", 1);
		*rr_chance = 0;
	}
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack, size_t *rr_chance)
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
	if (rr_chance != NULL)
	{
		if (*rr_chance == 1)
			ft_putendl_fd("rb", 1);
		*rr_chance = 0;
	}
	ft_putendl_fd("rrb", 1);
}
