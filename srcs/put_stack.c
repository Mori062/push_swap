/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:38:44 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/09 14:02:09 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	convert_size_t2int(size_t num)
{
	if (num > INT_MAX)
		return (INT_MAX);
	else
		return ((int)num);
}

int	convert_size_t2int_overfloated(size_t num)
{
	if (num > INT_MAX)
		return ((int)(num - INT_MAX));
	else
		return (0);
}

int	*putargs2stack(int argc, char **argv, size_t counter)
{
	int		*arr;
	char	**split;
	int		i;

	i = 0;
	// arr = (int *)malloc(sizeof(int) * (convert_size_t2int(counter)
	// 		+ convert_size_t2int_overfloated(counter)));
	arr = (int *)malloc(sizeof(int) * (counter));
	if (!arr)
		return (NULL);
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
