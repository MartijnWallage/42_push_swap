/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:39:52 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/07 18:22:23 by mwallage         ###   ########.fr       */
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
# define SA		"sa\n"
# define SB		"sb\n"
# define SS		"ss\n"
# define PA		"pa\n"
# define PB		"pb\n"
# define RA		"ra\n"
# define RB		"rb\n"
# define RR		"rr\n"
# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

typedef struct s_disc
{
	char			stack;
	int				rank;
	int				index;
	int				cost;
	struct s_disc	*next;
}					t_disc;

typedef struct s_table
{
	char	*op;
	int		try;
}			t_table; 

/* push_swap.c */
char	*get_next_op(void);
/*	disc.c */
int		disc_size(t_disc *disc);
void	*free_disc(t_disc *disc);
t_disc	*ft_disclast(t_disc *disc);
void	ft_discadd_front(t_disc **disc, t_disc *new);
t_disc	*ft_discnew(int nbr);
void	ft_discadd_back(t_disc **disc, t_disc *new);
t_disc	*get_args(int argc, char **argv);
/*	print.c	*/
void	display_discs(t_disc *a, t_disc *b);
void	display_instructions(char *instructions);
/*	utils.c	*/
t_disc	*previous(t_disc *head, t_disc *node);
t_disc	*next(t_disc *head, t_disc *node);
int		get_lowest_rank(t_disc *a);
int		get_highest_rank(t_disc *disc);
int		get_index(t_disc *disc, int rank);
int		min(int a, int b);
int		max(int a, int b);
t_disc	*get_by_index(t_disc *disc, int index);
/*	lower_ops.c */
void	swap(t_disc **head_ref);
void	push(t_disc **a, t_disc **b);
void	rotate(t_disc **a);
void	reverse_rotate(t_disc **a);
/*	higher_ops	*/
void	move_to_front(t_disc **a, int index);
void	exec_op(t_disc **a, t_disc **b, char *op);
void	double_revrot(t_disc **a, t_disc **b);
void	double_rot(t_disc **a, t_disc **b);
/*	try_ops.c */
int		try_swap(t_disc **a);
int		try_push(t_disc **a, t_disc **b);
int		try_rotate(t_disc **a, int target);
int		try_reverse_rotate(t_disc **a, int target);
/*	check_ sort.c	*/
int		is_ascending(t_disc *disc);
int		is_sorted(t_disc *disc);
int		is_sorted_pair(t_disc *disc, t_disc *node);
int		first_wrong_pair(t_disc *a);
int		wrong_pairs(t_disc *disc);
/*	sort.c */
void	sort_stack(t_disc **a, t_disc **b);
void	calc_pushcosts(t_disc *a, t_disc *b);
t_disc	*find_cheapest(t_disc *disc);
void	double_move_to_front(t_disc **a, int target_a, t_disc **b, int target_b);

#endif
