/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:34:22 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/04 17:22:36 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_one_commandline(char **argv)
{
	int		i;
	int		flag;
	char	**split;

	i = 0;
	flag = 0;
	split = ft_split(argv[1], ' ');
	while (split[i] != NULL)
	{
		if (ft_isint(split[i]) == 0)
			flag++;
		i++;
	}
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (flag > 0)
		return (1);
	return (0);
}

int	check_many_commandlines(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isint(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
		return (check_one_commandline(argv));
	else
		return (check_many_commandlines(argv));
}
