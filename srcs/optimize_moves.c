#include "push_swap.h"

// check_ss(moves);
// check_rr(moves);
// check_rrr(moves);
// check_rra_ra(moves);
// check_rrb_rb(moves);

void	check_ss(t_moves *moves)
{
	if (moves->next == NULL)
		return ;
	if ((moves->command == SA && moves->next->command == SB) ||
		(moves->command == SB && moves->next->command == SA))
	{
		moves->command = SS;
		free(moves->next);
		moves->next = moves->next->next;
	}
}

void	check_rr(t_moves *moves)
{
	if (moves->next == NULL)
		return ;
	if ((moves->command == RA && moves->next->command == RB) ||
		(moves->command == RB && moves->next->command == RA))
	{
		moves->command = RR;
		free(moves->next);
		moves->next = moves->next->next;
	}
}

void	check_rrr(t_moves *moves)
{
	if (moves->next == NULL)
		return ;
	if ((moves->command == RRA && moves->next->command == RRB) ||
		(moves->command == RRB && moves->next->command == RRA))
	{
		moves->command = RRR;
		free(moves->next);
		moves->next = moves->next->next;
	}
}

void	check_rra_ra(t_moves *moves)
{
	t_moves	*tmp;

	if (moves->next == NULL || moves->next->next == NULL)
		return ;
	tmp = moves->next;
	if ((moves->command == RRA && tmp->next->command == RA) ||
		(moves->command == RA && tmp->next->command == RRA))
	{
		tmp = tmp->next->next;
		free(moves->next);
		free(moves->next->next);
		moves->next = tmp;
	}
}

void	check_rrb_rb(t_moves *moves)
{
	t_moves	*tmp;

	if (moves->next == NULL || moves->next->next == NULL)
		return ;
	tmp = moves->next;
	if ((moves->command == RRB && tmp->next->command == RB) ||
		(moves->command == RB && tmp->next->command == RRB))
	{
		tmp = tmp->next->next;
		free(moves->next);
		free(moves->next->next);
		moves->next = tmp;
	}
}