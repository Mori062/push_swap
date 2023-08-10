/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:38:44 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/09 18:17:47 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*putargs2stack(int *arr, int argc, char **argv)
{
	char	**split;
	int		i;

	i = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i] != NULL)
		{
			arr[i] = ft_atoi(split[i]);
			free(split[i]);
			i++;
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
