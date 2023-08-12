/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:32:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/12 14:15:34 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

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

int					err_msg(void);
int					check_args(int argc, char **argv);
int					check_sorted(t_dock *dock);
int					check_duplicate(int *args, size_t counter);
size_t				*args_index(int *args, size_t counter);
int					*putargs2stack(int *arr, int argc, char **argv);
void				putindex(t_stack *stack, size_t *index, size_t counter);
t_dock				*dock_new(int *args, size_t counter);
void				make_king_deshret(t_dock **dock, size_t index_max,
						size_t block_num);
void				free_all(t_dock *dock, size_t *index);

void				sort(t_dock *dock, size_t counter);
void				sort2(t_dock *dock);
void				sort3(t_dock *dock, size_t min_index);
void				sort4(t_dock *dock, size_t min_index);
void				sort5(t_dock *dock, size_t min_index);
void				sort_many(t_dock *dock, size_t index_max, size_t block_num);

void				sa(t_stack **stack, size_t *rr_chance);
void				sb(t_stack **stack, size_t *rr_chance);

void				ra(t_stack **stack, size_t *rr_chance);
void				rb(t_stack **stack, size_t *rr_chance);

void				rra(t_stack **stack, size_t *rr_chance);
void				rrb(t_stack **stack, size_t *rr_chance);

void				pa(t_stack **stack_a, t_stack **stack_b, size_t *rr_chance);
void				pb(t_stack **stack_a, t_stack **stack_b, size_t *rr_chance);

#endif