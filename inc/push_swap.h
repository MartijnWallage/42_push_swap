/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:39:52 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/30 16:15:59 by mwallage         ###   ########.fr       */
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
# define SA		0
# define SB		1
# define SS		2
# define PA		3
# define PB		4
# define RA		5
# define RB		6
# define RR		7
# define RRA	8
# define RRB	9
# define RRR	10

typedef struct s_disc
{
	int				rank;
	int				index;
	struct s_disc	*next;
}					t_disc;

typedef struct s_table
{
	char	*op;
	int		try;
}			t_table; 

/* push_swap.c */
char		*get_next_op(void);
/*	disc.c */
int			disc_size(t_disc *disc);
void		*free_disc(t_disc *disc);
t_disc		*ft_disclast(t_disc *disc);
void		ft_discadd_front(t_disc **disc, t_disc *new);
t_disc		*ft_discnew(int nbr);
void		ft_discadd_back(t_disc **disc, t_disc *new);
t_disc		*get_args(int argc, char **argv);
/*	print.c	*/
void		display_discs(t_disc *a, t_disc *b);
void		display_instructions(char *instructions);
/*	utils.c	*/
t_disc		*get_prev_node(t_disc *head, t_disc *node);
/*	ops.c */
void		swap(t_disc **head_ref);
void		push(t_disc **a, t_disc **b);
void		exec_op(t_disc **a, t_disc **b, char *op);
void		exec_instructions(t_disc **a, t_disc **b);
/*	sort.c	*/
int			is_ascending(t_disc *stack);
int			is_sorted(t_disc *a);
int			disc_sorted(t_disc *disc, int a);
char		*sort_stack(t_disc **a, t_disc **b);
/*	score.c */
int			score(t_disc *a, t_disc *b);
void		calculate_scores(t_disc **a, t_disc **b, t_table *scores);
char		*best_op(t_table *scores);

#endif
