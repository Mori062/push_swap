/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:32:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 01:42:34 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

# define BLOCK_NUM 55
// 100 のときは 30 が最適
// 500 のときは 55 が最適

typedef struct s_stack
{
	int				original;
	size_t			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_dock
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_dock;

void				sort(t_dock *dock, size_t counter);

int					check_args(int argc, char **argv);

int					err_msg(void);

int					check_duplicate(int *args, size_t counter);

t_dock				*dock_new(int *args, size_t counter);

size_t				*args_index(int *args, size_t counter);
void				putindex(t_stack *stack, size_t *index, size_t counter);

int					*putargs2stack(int *arr, int argc, char **argv);

// sa, sb, ss
void				sa(t_stack **stack, size_t *rr_chance);
void				sb(t_stack **stack, size_t *rr_chance);
// void				ss(t_dock *dock);
// ra, rb, rr
void				ra(t_stack **stack, size_t *rr_chance);
void				rb(t_stack **stack, size_t *rr_chance);
// void				rr(t_dock *dock);
// rra, rrb, rrr
void				rra(t_stack **stack, size_t *rr_chance);
void				rrb(t_stack **stack, size_t *rr_chance);
// void				rrr(t_dock *dock);
// pa, pb
void				pa(t_stack **stack_a, t_stack **stack_b, size_t *rr_chance);
void				pb(t_stack **stack_a, t_stack **stack_b, size_t *rr_chance);

#endif