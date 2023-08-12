/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/12 14:12:39 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_if_half(t_dock **dock, size_t counter)
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

static void	free_candidate(t_dock **dock, size_t *flag, size_t *index_max)
{
	pa(&(*dock)->stack_a, &(*dock)->stack_b, 0);
	(*index_max)--;
	if (*flag == 1)
	{
		sa(&(*dock)->stack_a, 0);
		(*index_max)--;
		(*flag) = 0;
	}
}

static void	found_candidate(t_dock **dock, size_t *flag)
{
	pa(&(*dock)->stack_a, &(*dock)->stack_b, 0);
	(*flag) = 1;
}

void	sort_many(t_dock *dock, size_t index_max, size_t block_num)
{
	size_t		flag;

	flag = 0;
	index_max--;
	make_king_deshret(&dock, index_max, block_num);
	sort5(dock, index_max - 4);
	while (dock->stack_b != NULL)
	{
		if (dock->stack_b->index == index_max - 5)
			free_candidate(&dock, &flag, &index_max);
		else if (find_if_half(&dock, index_max) == 1)
		{
			if (dock->stack_b->index == index_max - 6 && flag == 0)
				found_candidate(&dock, &flag);
			rb(&dock->stack_b, 0);
		}
		else
		{
			if (dock->stack_b->index == index_max - 6 && flag == 0)
				found_candidate(&dock, &flag);
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
