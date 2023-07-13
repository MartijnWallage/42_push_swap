/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:39:52 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/13 15:38:23 by mwallage         ###   ########.fr       */
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
# define ERROR "Error"

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

/*	args.c */
void	*ft_error(char *message);
t_disc	*get_args(int argc, char **argv);
/*	disc.c */
int		disc_size(t_disc *disc);
void	*free_disc(t_disc *disc);
t_disc	*ft_disclast(t_disc *disc);
void	ft_discadd_front(t_disc **disc, t_disc *new);
t_disc	*ft_discnew(int nbr);
void	ft_discadd_back(t_disc **disc, t_disc *new);
/*	utils.c	*/
t_disc	*previous(t_disc *head, t_disc *node);
t_disc	*next(t_disc *head, t_disc *node);
t_disc	*get_lowest(t_disc *a);
t_disc	*get_highest(t_disc *disc);
t_disc	*get_by_index(t_disc *disc, int index);
/*	lower_ops.c */
void	swap(t_disc **head_ref);
void	push(t_disc **a, t_disc **b);
void	rotate(t_disc **a);
void	reverse_rotate(t_disc **a);
/*	higher_ops	*/
void	move_to_front(t_disc **a, int index);
void	exec_op(t_disc **a, t_disc **b, const char *op);
void	double_move_to_front(t_disc **a, int target_a, t_disc **b, int target_b);
/*	check_ sort.c	*/
int		is_ascending(t_disc *disc);
int		is_sorted(t_disc *disc);
int		wrong_pairs(t_disc *disc);
t_disc	*find_cheapest(t_disc *a, t_disc *b);
int		find_place(t_disc *disc, int target);
/*	sort.c */
void	sort_stack(t_disc **a, t_disc **b);


#endif
