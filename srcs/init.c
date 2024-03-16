#include "push_swap.h"

static void	stack_push_back(t_data *data, int num);

t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)xmalloc(sizeof(t_data));
	data->stack_a = NULL;
	data->stack_b = NULL;
	return (data);
}

t_result	*result_init(void)
{
	t_result	*result;

	result = (t_result *)xmalloc(sizeof(t_result));
	result->moves_one = NULL;
	result->moves_two = NULL;
	result->moves_three = NULL;
	return (result);
}

void	put_args_to_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stack_push_back(data, atoi(argv[i]));
		i++;
	}
}

static void	stack_push_back(t_data *data, int num)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack *)xmalloc(sizeof(t_stack));
	new->original = num;
	new->index = 0;
	new->next = NULL;
	new->original_next = NULL;
	if (!data->stack_a)
	{
		new->prev = NULL;
		data->stack_a = new;
	}
	else
	{
		last = data->stack_a;
		while (last->next)
			last = last->next;
		last->next = new;
		last->original_next = new;
		new->prev = last;
	}
}