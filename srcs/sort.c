/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/11 11:44:42 by morishitash      ###   ########.fr       */
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

int	find_counter_up_20(t_dock *dock, size_t counter)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = dock->stack_b;
	while (i < 20)
	{
		if (tmp->index == counter)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	make_king_deshret(t_dock **dock)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while ((*dock)->stack_a != NULL)
	{
		if (i == 21)
		{
			num += 21;
			i = 0;
		}
		if ((*dock)->stack_a->index <= 21 + num)
		{
			pb(&(*dock)->stack_a, &(*dock)->stack_b);
			if ((*dock)->stack_b->index <= 7 + num)
				rb(&(*dock)->stack_b);
			i++;
		}
		else
			ra(&(*dock)->stack_a);
	}
}

void	sort_many(t_dock *dock, size_t counter)
{
	counter--;
	make_king_deshret(&dock);
	while (dock->stack_b != NULL)
	{
		if (dock->stack_b->index == counter)
		{
			pa(&dock->stack_a, &dock->stack_b);
			counter--;
		}
		else if (find_counter_up_20(dock, counter) == 1)
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
