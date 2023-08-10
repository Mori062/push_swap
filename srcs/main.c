/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:49 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/11 00:17:05 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	count_node(int argc, char **argv)
{
	int		i;
	int		flag;
	long	counter;

	flag = 0;
	counter = 0;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_isdigit(argv[1][i]) == 1)
			{
				if (flag == 0)
					counter++;
				flag = 1;
			}
			else
				flag = 0;
			i++;
		}
		return (counter);
	}
	else
		return ((size_t)argc - 1);
}

int	main(int argc, char **argv)
{
	int		*args;
	size_t	num_counter;
	size_t	*index;
	t_dock	*dock;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv) == 1)
		return (err_msg());
	num_counter = count_node(argc, argv);
	args = (int *)malloc(sizeof(int) * (num_counter));
	if (!args)
		return (1);
	args = putargs2stack(args, argc, argv);
	if (check_duplicate(args, num_counter) == 1)
	{
		free(args);
		return (err_msg());
	}
	dock = dock_new(args, num_counter);
	index = args_index(args, num_counter);
	putindex(dock->stack_a, index, num_counter);
	sort(dock, num_counter);
	return (0);
}
