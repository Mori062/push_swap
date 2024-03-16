/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:32:11 by morishitash       #+#    #+#             */
/*   Updated: 2024/03/16 12:34:45 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libc.h>
# include <stdbool.h>
# include <ctype.h>

typedef struct s_stack	t_stack;
typedef struct s_moves	t_moves;

typedef struct s_stack
{
	t_stack		*next;
	t_stack		*prev;
	t_stack		*original_next;
	int			original;
	int			index;
}				t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_data;

typedef struct s_result
{
	t_moves	*moves_one;
	t_moves	*moves_two;
	t_moves	*moves_three;
}				t_result;

typedef enum e_command
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_command;

typedef struct s_moves
{
	t_command	command;
	t_moves		*next;
}				t_moves;

t_result	*result_init(void);
t_data	*data_init(void);
void	put_args_to_data(t_data *data, int argc, char **argv);

void compress_num(t_data *data);

bool	arg_invalid(int argc, char **argv);
bool	is_sorted(t_data *data);

void	*xmalloc(size_t size);
int	error_exit(void);

void sort_one(t_data *data, t_result *result);
void sort_two(t_data *data, t_result *result);
void sort_three(t_data *data, t_result *result);

void	check_ss(t_moves *moves);
void	check_rr(t_moves *moves);
void	check_rrr(t_moves *moves);
void	check_rra_ra(t_moves *moves);
void	check_rrb_rb(t_moves *moves);

#endif