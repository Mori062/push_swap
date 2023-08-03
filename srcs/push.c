/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:01:57 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/03 17:13:23 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_dock *dock)
{
	t_stack	*tmp;

	tmp = dock->stack_b;
	dock->stack_b = dock->stack_b->next;
	dock->stack_b->prev = NULL;
	tmp->next = dock->stack_a;
	dock->stack_a = tmp;
	dock->stack_a->prev = NULL;
}

void	pb(t_dock *dock)
{
	t_stack	*tmp;

	tmp = dock->stack_a;
	dock->stack_a = dock->stack_a->next;
	dock->stack_a->prev = NULL;
	tmp->next = dock->stack_b;
	dock->stack_b = tmp;
	dock->stack_b->prev = NULL;
}