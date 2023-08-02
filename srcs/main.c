/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:49 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/03 03:43:31 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	err_msg(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

int	count_node(int argc, char **argv)
{
	int	i;
	int	flag;
	int	counter;

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
					counter ++;
				flag = 1;
			}
			else
				flag = 0;
			i++;
		}
		return (counter);
	}
	else
		return (argc - 1);
}

int    sort(int *args, int num)
{
    if (num = 1)
        return (0);
    else if (num == 2)
        return (sort2(args));
    else if (num == 3)
        return (sort3(args));
    else if (num == 4)
        return (sort4(args));
    else if (num == 5)
        return (sort5(args));
    else
        return (sort_many(args));
}

int	main(int argc, char **argv)
{
	int		*args;
	int		num_counter;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv) == 1)
		return (err_msg());
	num_counter = count_node(argc, argv);
	args = putargs2stack(argc, argv, num_counter);
	sort(args, num_counter);
	return (0);
}
