/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/03 16:22:11 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort2(t_dock *dock)
{
	if (dock->stack_a->index > dock->stack_a->next->index)
	{
		sa(dock->stack_a);
		ft_putendl_fd("sa", 1);
	}
}

void	sort3(t_dock *dock)
{
	if (dock->stack_a->index == 0)
	{
		if (dock->stack_a->next->index == 2)
		{
			sa(dock->stack_a);
			ft_putendl_fd("sa", 1);
		}
	}
}
