/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:49 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/03 18:57:02 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	err_msg(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

size_t	count_node(int argc, char **argv)
{
	int	i;
	int	flag;
	size_t	counter;

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


// void	store_dock(t_dock *dock, int *args, int counter)
// {
// 	int	i;

// 	i = 0;
// 	while (i < counter)
// 	{
// 		push(dock->stack_a, args[i]);
// 		i++;
// 		dock->stack_a = dock->stack_a->next;
// 	}
// }

// void	init_dock(t_dock *dock)
// {
// 	dock->stack_a = NULL;
// 	dock->stack_b = NULL;
// }

//push

// void	push(t_stack *stack, int data)
// {
// 	t_node	*new_node;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (new_node == NULL)
// 		return ;
// 	new_node->original = data;
// 	new_node->index = -1;
// 	stack->node = new_node;
// 	stack->next = NULL;
// 	stack->prev = NULL;
// }

t_dock	*dock_new(size_t *args, size_t counter)
{
	t_dock	*dock;
	t_stack	*tmp;
	size_t		i;

	dock = (t_dock *)malloc(sizeof(t_dock));
	if (dock == NULL)
		return (NULL);
	dock->stack_a = NULL;
	dock->stack_b = NULL;
	i = 0;
	while (i < counter)
	{
		push(dock->stack_a, args[i]);
		if (i > 0)
		{
			dock->stack_a->prev = tmp;
			dock->stack_a->prev->next = dock->stack_a;
		}
		else
			dock->stack_a->prev = NULL;
		tmp = dock->stack_a;
		i++;
	}
	while (dock->stack_a->prev != NULL)
		dock->stack_a = dock->stack_a->prev;
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
	size_t	*args;
	size_t	num_counter;
	int		*index;
	t_dock	*dock;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv) == 1)
		return (err_msg());
	printf("check_args OK\n");
	num_counter = count_node(argc, argv);
	args = putargs2stack(argc, argv, num_counter);
	dock = dock_new(args, num_counter);
	index = sort_args(args, num_counter);
	putindex(dock->stack_a, index, num_counter);
	sort(dock, num_counter);
	return (0);
}
