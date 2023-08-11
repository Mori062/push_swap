/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/11 20:56:05 by morishitash      ###   ########.fr       */
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

int	find_counter_up_num(t_dock **dock, size_t counter)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = (*dock)->stack_b;
	while (i < (BLOCK_NUM / 3 * 2))
	{
		if (tmp->index == counter - 5)
			return (1);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	make_king_deshret(t_dock **dock, size_t index_max)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while ((*dock)->stack_a->next->next->next->next->next != NULL)
	{
		if (i == BLOCK_NUM)
		{
			num += BLOCK_NUM;
			i = 0;
		}
		if ((*dock)->stack_a->index > index_max - 5)
			ra(&(*dock)->stack_a);
		else if ((*dock)->stack_a->index <= BLOCK_NUM + num)
		{
			pb(&(*dock)->stack_a, &(*dock)->stack_b);
			if ((*dock)->stack_b->index <= (BLOCK_NUM / 3) + num)
				rb(&(*dock)->stack_b);
			i++;
		}
		else
			ra(&(*dock)->stack_a);
	}
}

void	sort_many(t_dock *dock, size_t index_max)
{
	index_max--;
	make_king_deshret(&dock, index_max);
	sort5(dock, index_max - 4);
	while (dock->stack_b != NULL)
	{
		if (dock->stack_b->index >= index_max - 5)
		{
			pa(&dock->stack_a, &dock->stack_b);
			index_max--;
		}
		else if (find_counter_up_num(&dock, index_max) == 1)
			rb(&dock->stack_b);
		else
			rrb(&dock->stack_b);
	}
}

int	check_sorted(t_dock *dock)
{
	t_stack	*tmp;

	tmp = dock->stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// sort
void	sort(t_dock *dock, size_t counter)
{
	if (check_sorted(dock) == 1)
		return ;
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
