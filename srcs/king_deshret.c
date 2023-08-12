/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   king_deshret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 02:32:56 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 02:34:17 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	update_things(size_t *i, size_t *num, size_t block_num)
{
	*num += block_num;
	*i = 0;
}

static void	king_deshret_init(size_t *i, size_t *num, size_t *rr_chance)
{
	*i = 0;
	*num = 0;
	*rr_chance = 0;
}

void	make_king_deshret(t_dock **dock, size_t index_max, size_t block_num)
{
	size_t	i;
	size_t	num;
	size_t	rr_chance;

	king_deshret_init(&i, &num, &rr_chance);
	while ((*dock)->stack_a->next->next->next->next->next != NULL)
	{
		if (i == block_num)
			update_things(&i, &num, block_num);
		if ((*dock)->stack_a->index > index_max - 5)
			ra(&(*dock)->stack_a, &rr_chance);
		else if ((*dock)->stack_a->index <= block_num + num)
		{
			pb(&(*dock)->stack_a, &(*dock)->stack_b, &rr_chance);
			if ((*dock)->stack_b->index <= (block_num / 2) + num)
				rb(&(*dock)->stack_b, &rr_chance);
			i++;
		}
		else
			ra(&(*dock)->stack_a, &rr_chance);
	}
	if (rr_chance == 1)
		ft_putendl_fd("rb", 1);
}
