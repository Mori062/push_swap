/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:29:24 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/09 14:34:49 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	*args_index(int *args, size_t counter)
{
	size_t	*sorted;
	size_t	i;
	size_t	j;
	size_t	count;

	sorted = (size_t *)malloc(sizeof(size_t) * counter);
	if (sorted == NULL)
		return (NULL);
	i = 0;
	while (i < counter)
	{
		j = 0;
		count = 0;
		while (j < counter)
		{
			if (args[i] > args[j])
				count++;
			j++;
		}
		sorted[i] = count;
		i++;
	}
	// free(args);
	return (sorted);
}

void	putindex(t_stack *stack, size_t *index, size_t counter)
{
	size_t	i;

	i = 0;
	while (i < counter)
	{
		stack->index = index[i];
		i++;
		stack = stack->next;
	}
}
