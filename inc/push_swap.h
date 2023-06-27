/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:39:52 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 14:21:00 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/inc/libft.h"
# include <stdio.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"


typedef struct s_table
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}				t_table;

/*	print.c	*/
void	display_stacks(t_list *a, t_list *b);
void	display_instructions(char *instructions);
/*	utils.c	*/
void	*free_stack(t_list *stack);
t_list	*get_args(int argc, char **argv);
char	*reverse_op(char *last);
t_list	*get_previous_node(t_list *head, t_list *node);
/*	instructions.c */
void	swap(t_list **head_ref);
void	push(t_list **a, t_list **b);
void	exec_op(t_list **a, t_list **b, char *op);
void	exec_instructions(t_list **a, t_list **b);
/*	sort.c	*/
int		is_ascending(t_list *stack);
int		is_sorted(t_list *a);
char	*sort_stack(t_list **a, t_list **b, char *instructions);
/*	score.c */
int		score(t_list *a, t_list *b);
void	calculate_scores(t_list **a, t_list **b, t_table *scores);
char	*best_op(t_table *scores);

#endif
