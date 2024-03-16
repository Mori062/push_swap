#include "push_swap.h"

void sort_one(t_data *data, t_result *result)
{
	(void)data;
	optimize_moves(result->moves_one);
}

void sort_two(t_data *data, t_result *result)
{
	(void)data;
	optimize_moves(result->moves_two);
}

void sort_three(t_data *data, t_result *result)
{
	(void)data;
	optimize_moves(result->moves_three);
}