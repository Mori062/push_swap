/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/11 01:26:01 by morishitash      ###   ########.fr       */
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

void	sort3(t_dock *dock, size_t min_index)
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

void	sort4(t_dock *dock, size_t min_index)
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

void	sort5(t_dock *dock, size_t min_index)
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

void	sort_many(t_dock *dock, size_t counter)
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 1;
	counter--;
	while (dock->stack_a != NULL)
	{
		if (i == 20)
		{
			num++;
			i = 0;
		}
		if (dock->stack_a->index <= 18 * num)
		{
			pb(&dock->stack_a, &dock->stack_b);
			rb(&dock->stack_b);
			i++;
		}
		else if (dock->stack_a->index <= 20 * num)
		{
			pb(&dock->stack_a, &dock->stack_b);
			i++;
		}
		else
			ra(&dock->stack_a);
	}
	while (dock->stack_b != NULL)
	{
		if (dock->stack_b->index == counter)
		{
			pa(&dock->stack_a, &dock->stack_b);
			counter--;
		}
		else if (dock->stack_b->next->index == counter
			|| dock->stack_b->next->next->index == counter
			|| dock->stack_b->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->index
			== counter
			|| dock->stack_b->next->next->next->next->next->next->next->index
			== counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->next->next->next->next->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->next->next->next->next->next
			->index == counter
			|| dock->stack_b->next->next->next->next->next->next->next->next
			->next->next->next->next->next->next->next->next->next->next
			->index == counter)
			rb(&dock->stack_b);
		else
			rrb(&dock->stack_b);
	}
}

// sort
void	sort(t_dock *dock, size_t counter)
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
	else
		sort_many(dock, counter);
}
