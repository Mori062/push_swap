#include "push_swap.h"

void	optimize_moves(t_moves *moves)
{
	if (moves == NULL)
		return ;
	while (moves->next)
	{
		check_ss(moves);
		check_rr(moves);
		check_rrr(moves);
		check_rra_ra(moves);
		check_rrb_rb(moves);
		moves = moves->next;
	}
}
