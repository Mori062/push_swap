/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:01:57 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/10 11:43:43 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_dock **dock)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*dock)->stack_b;
	tmp2 = (*dock)->stack_a;
	(*dock)->stack_b = (*dock)->stack_b->next;
	(*dock)->stack_b->prev = NULL;
	tmp->next = tmp2;
	tmp->prev = NULL;
	tmp2->prev = tmp;
	(*dock)->stack_a = tmp;
	ft_putendl_fd("pa", 1);
}

void	pb(t_dock **dock)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*dock)->stack_b;
	tmp2 = (*dock)->stack_a;
	(*dock)->stack_b = (*dock)->stack_b->next;
	(*dock)->stack_b->prev = NULL;
	tmp->next = tmp2;
	tmp->prev = NULL;
	tmp2->prev = tmp;
	(*dock)->stack_a = tmp;
	ft_putendl_fd("pb", 1);
}
