/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:38:44 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/03 03:04:48 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *putargs2stack(int argc, char **argv, int counter)
{
	int     *arr;
	char    **split;
	int     i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * counter);
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
