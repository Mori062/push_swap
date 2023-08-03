/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:32:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/03 17:14:55 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				original;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;


typedef struct s_dock
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_dock;

int					check_args(int argc, char **argv);

int	*putargs2stack(int argc, char **argv, int counter);

// sa, sb, ss
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_dock *dock);
// ra, rb, rr
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_dock *dock);
// rra, rrb, rrr
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_dock *dock);
// pa, pb
void	pa(t_dock *dock);
void	pb(t_dock *dock);

#endif