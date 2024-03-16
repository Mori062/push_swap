#include "push_swap.h"

static bool	check_without_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_overflow(int argc, char **argv)
{
	int		i;
	long	check_num;

	i = 1;
	check_num = 0;
	while (i < argc)
	{
		check_num = strtol(argv[i], NULL, 10);
		if (check_num > INT_MAX || check_num < INT_MIN)
			return (true);
		i++;
	}
	return (false);
}

static bool	check_dupulicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	arg_invalid(int argc, char **argv)
{
	if (check_without_num(argc, argv))
		return (true);
	if (check_overflow(argc, argv))
		return (true);
	if (check_dupulicate(argc, argv))
		return (true);
	return (false);
}

bool	is_sorted(t_data *data)
{
	t_stack	*stack;

	stack = data->stack_a;
	while (stack->next)
	{
		if (stack->original > stack->next->original)
			return (false);
		stack = stack->next;
	}
	return (true);
}