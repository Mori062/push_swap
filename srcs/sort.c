/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/10 13:25:03 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sort2(t_dock *dock)
{
	if (dock->stack_a->index > dock->stack_a->next->index)
	{
		sa(&dock->stack_a);
	}
}

void	sort3(t_dock *dock, int min_index)
{
	if (dock->stack_a->index == min_index
		&& dock->stack_a->next->index == min_index + 2)
	{
		rra(&dock->stack_a);
		sa(&dock->stack_a);
	}
	else if (dock->stack_a->index == min_index + 1
		&& dock->stack_a->next->index == min_index)
		sa(&dock->stack_a);
	else if (dock->stack_a->index == min_index + 1
		&& dock->stack_a->next->index == min_index + 1)
		ra(&dock->stack_a);
	else if (dock->stack_a->index == min_index + 1
		&& dock->stack_a->next->index == min_index + 2)
		rra(&dock->stack_a);
	else if (dock->stack_a->index == min_index + 2
		&& dock->stack_a->next->index == min_index)
		ra(&dock->stack_a);
	else if (dock->stack_a->index == min_index + 2
		&& dock->stack_a->next->index == min_index + 1)
	{
		ra(&dock->stack_a);
		sa(&dock->stack_a);
	}
}

void	sort4(t_dock *dock, int min_index)
{
	if (dock->stack_a->index == min_index)
		;
	else if (dock->stack_a->next->index == min_index)
		ra(&dock->stack_a);
	else
	{
		while (dock->stack_a->index != min_index)
			rra(&dock->stack_a);
	}
	pb(&dock->stack_a, &dock->stack_b);
	sort3(dock, min_index + 1);
	pa(&dock->stack_a, &dock->stack_b);
}

void	sort5(t_dock *dock, int min_index)
{
	if (dock->stack_a->index == min_index)
		;
	else if (dock->stack_a->next->index == min_index)
		ra(&dock->stack_a);
	else if (dock->stack_a->next->next->index == min_index)
	{
		ra(&dock->stack_a);
		ra(&dock->stack_a);
	}
	else
	{
		while (dock->stack_a->index != min_index)
			rra(&dock->stack_a);
	}
	pb(&dock->stack_a, &dock->stack_b);
	sort4(dock, min_index + 1);
	pa(&dock->stack_a, &dock->stack_b);
}

// sort
void	sort(t_dock *dock, int counter)
{
	if (counter == 1)
		return ;
	else if (counter == 2)
		sort2(dock);
	else if (counter == 3)
		sort3(dock, 0);
	else if (counter == 4)
		sort4(dock, 0);
	else if (counter == 5)
		sort5(dock, 0);
	// else
	// 	sort_many(dock, counter);
}
