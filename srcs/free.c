/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:56:43 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 14:04:17 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_dock(t_dock *dock)
{
	t_stack	*tmp;

	while (dock->stack_a != NULL)
	{
		tmp = dock->stack_a;
		dock->stack_a = dock->stack_a->next;
		free(tmp);
	}
	while (dock->stack_b != NULL)
	{
		tmp = dock->stack_b;
		dock->stack_b = dock->stack_b->next;
		free(tmp);
	}
	free(dock);
}

void	free_all(t_dock *dock, size_t *index)
{
	free_dock(dock);
	free(index);
}
