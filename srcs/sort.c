/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/12 02:15:06 by morishitash      ###   ########.fr       */
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

int	find_if_half(t_dock **dock, size_t counter)
{
	size_t	i;
	size_t	j;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = (*dock)->stack_b;
	while ((*dock)->stack_b->next != NULL)
	{
		(*dock)->stack_b = (*dock)->stack_b->next;
		i++;
	}
	while ((*dock)->stack_b->prev != NULL)
		(*dock)->stack_b = (*dock)->stack_b->prev;
	i /= 2;
	while (tmp->next != NULL)
	{
		if (j == i)
			break ;
		if (tmp->index == counter - 5)
			return (1);
		tmp = tmp->next;
		j++;
	}
	return (0);
}

void	update_things(size_t *i, size_t *num)
{
	*num += BLOCK_NUM;
	*i = 0;
}

void	king_desheret_init(size_t *i, size_t *num, size_t *rr_chance)
{
	*i = 0;
	*num = 0;
	*rr_chance = 0;
}


void	make_king_deshret(t_dock **dock, size_t index_max)
{
	size_t	i;
	size_t	num;
	size_t	rr_chance;

	king_desheret_init(&i, &num, &rr_chance);
	while ((*dock)->stack_a->next->next->next->next->next != NULL)
	{
		if (i == BLOCK_NUM)
			update_things(&i, &num);
		if ((*dock)->stack_a->index > index_max - 5)
			ra(&(*dock)->stack_a, &rr_chance);
		else if ((*dock)->stack_a->index <= BLOCK_NUM + num)
		{
			pb(&(*dock)->stack_a, &(*dock)->stack_b, &rr_chance);
			if ((*dock)->stack_b->index <= (BLOCK_NUM / 2) + num)
				rb(&(*dock)->stack_b, &rr_chance);
			i++;
		}
		else
			ra(&(*dock)->stack_a, &rr_chance);
	}
	if (rr_chance == 1)
		ft_putendl_fd("rb", 1);
}

void	sort_many(t_dock *dock, size_t index_max)
{
	int	flag;

	flag = 0;
	index_max--;
	make_king_deshret(&dock, index_max);
	sort5(dock, index_max - 4);
	while (dock->stack_b != NULL)
	{
		if (dock->stack_b->index == index_max - 5)
		{
			pa(&dock->stack_a, &dock->stack_b, 0);
			index_max--;
			if (flag == 1)
			{
				sa(&dock->stack_a, 0);
				index_max--;
				flag = 0;
			}
		}
		else if (find_if_half(&dock, index_max) == 1)
		{
			if (dock->stack_b->index == index_max - 6 && flag == 0)
			{
				pa(&dock->stack_a, &dock->stack_b, 0);
				flag = 1;
			}
			rb(&dock->stack_b, 0);
		}
		else
		{
			if (dock->stack_b->index == index_max - 6 && flag == 0)
			{
				pa(&dock->stack_a, &dock->stack_b, 0);
				flag = 1;
			}
			rrb(&dock->stack_b, 0);
		}
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
