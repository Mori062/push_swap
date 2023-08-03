/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:38:44 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/03 18:38:44 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	*putargs2stack(int argc, char **argv, size_t counter)
{
	size_t	*arr;
	char	**split;
	int		i;

	i = 0;
	arr = (size_t *)malloc(sizeof(size_t) * counter);
	if (!arr)
		return (NULL);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i] != NULL)
		{
			arr[i] = ft_atoi(split[i]);
			i++;
			free(split[i]);
		}
		free(split);
	}
	else
	{
		while (argv[i + 1] != NULL)
		{
			arr[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	return (arr);
}
