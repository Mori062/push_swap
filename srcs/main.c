/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:49 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/06 16:52:51 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	count_node(int argc, char **argv)
{
	int	i;
	int	flag;
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

void	push(t_stack *stack, int data)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return ;
	stack->original = data;
	stack->index = -1;
	stack->next = NULL;
}

t_dock	*dock_new(long *args, size_t counter)
{
	t_dock	*dock;
	t_stack	*tmp;
	size_t	i;

	dock = (t_dock *)malloc(sizeof(t_dock));
	if (dock == NULL)
		return (NULL);
	dock->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (dock->stack_a == NULL)
		return (NULL);
	dock->stack_b = NULL;
	tmp = dock->stack_a;
	i = 0;
	while (i < counter)
	{
		(args[i]);
		tmp = tmp->next;
		i++;
	}
	return (dock);
}

int	*sort_args(size_t *args, size_t counter)
{
	int		*sorted;
	size_t	i;
	size_t	j;
	size_t	count;

	sorted = (int *)malloc(sizeof(int) * counter);
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
	free(args);
	return (sorted);
}

void	putindex(t_stack *stack, int *index, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		stack->index = index[i];
		i++;
		stack = stack->next;
	}
}

//sort
void	sort(t_dock *dock, int counter)
{
	if (counter == 1)
		return ;
	else if (counter == 2)
		sort2(dock);
	// else if (counter == 3)
	// 	sort3(dock);
	// else if (counter == 4)
	// 	sort4(dock);
	// else if (counter == 5)
	// 	sort5(dock);
	// else
	// 	sort_many(dock, counter);
}

int	main(int argc, char **argv)
{
	long	*args;
	size_t	num_counter;
	int		*index;
	t_dock	*dock;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv) == 1)
		return (err_msg());
	num_counter = count_node(argc, argv);
	printf("check_args OK\n");
	args = putargs2stack(argc, argv, num_counter);
	dock = dock_new(args, num_counter);
	index = sort_args(args, num_counter);
	putindex(dock->stack_a, index, num_counter);
	sort(dock, num_counter);
	return (0);
}
