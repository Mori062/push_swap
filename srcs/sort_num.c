/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:05:53 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 02:34:43 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort2(t_dock *dock)
{
	if (dock->stack_a->index > dock->stack_a->next->index)
	{
		sa(&dock->stack_a, 0);
	}
}

void	sort3(t_dock *dock, size_t min_index)
{
	if (dock->stack_a->index == min_index
		&& dock->stack_a->next->index == min_index + 2)
	{
		rra(&dock->stack_a, 0);
		sa(&dock->stack_a, 0);
	}
	else if (dock->stack_a->index == min_index + 1
		&& dock->stack_a->next->index == min_index)
		sa(&dock->stack_a, 0);
	else if (dock->stack_a->index == min_index + 1
		&& dock->stack_a->next->index == min_index + 1)
		ra(&dock->stack_a, 0);
	else if (dock->stack_a->index == min_index + 1
		&& dock->stack_a->next->index == min_index + 2)
		rra(&dock->stack_a, 0);
	else if (dock->stack_a->index == min_index + 2
		&& dock->stack_a->next->index == min_index)
		ra(&dock->stack_a, 0);
	else if (dock->stack_a->index == min_index + 2
		&& dock->stack_a->next->index == min_index + 1)
	{
		ra(&dock->stack_a, 0);
		sa(&dock->stack_a, 0);
	}
}

void	sort4(t_dock *dock, size_t min_index)
{
	if (dock->stack_a->index == min_index)
		;
	else if (dock->stack_a->next->index == min_index)
		ra(&dock->stack_a, 0);
	else
	{
		while (dock->stack_a->index != min_index)
			rra(&dock->stack_a, 0);
	}
	pb(&dock->stack_a, &dock->stack_b, 0);
	sort3(dock, min_index + 1);
	pa(&dock->stack_a, &dock->stack_b, 0);
}

void	sort5(t_dock *dock, size_t min_index)
{
	if (dock->stack_a->index == min_index)
		;
	else if (dock->stack_a->next->index == min_index)
		ra(&dock->stack_a, 0);
	else if (dock->stack_a->next->next->index == min_index)
	{
		ra(&dock->stack_a, 0);
		ra(&dock->stack_a, 0);
	}
	else
	{
		while (dock->stack_a->index != min_index)
			rra(&dock->stack_a, 0);
	}
	pb(&dock->stack_a, &dock->stack_b, 0);
	sort4(dock, min_index + 1);
	pa(&dock->stack_a, &dock->stack_b, 0);
}
