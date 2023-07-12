/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:27 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	exec_op_noprint(t_disc **a, t_disc **b, char *op)
{
	if (!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "ss", 2))
		swap(a);
	if (!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2))
		swap(b);
	if (!ft_strncmp(op, "pa", 2))
		push(b, a);
	if (!ft_strncmp(op, "pb", 2))
		push(a, b);
	if (!ft_strncmp(op, "ra", 2) || !ft_strncmp(op, "rr", 3))
		rotate(a);
	if (!ft_strncmp(op, "rb", 2) || !ft_strncmp(op, "rr", 3))
		rotate(b);
	if (!ft_strncmp(op, "rra", 3) || !ft_strncmp(op, "rrr", 3))
		reverse_rotate(a);
	if (!ft_strncmp(op, "rrb", 3) || !ft_strncmp(op, "rrr", 3))
		reverse_rotate(b);
}

static int	is_valid_op(char *op)
{
	if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n")
		|| !ft_strcmp(op, "pa\n") || !ft_strcmp(op, "pb\n") || !ft_strcmp(op, "ra\n")
		|| !ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rr\n") || !ft_strcmp(op, "rra\n")
		|| !ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n"))
		return (1);
	return (0);	
}

int main(int argc, char **argv)
{
	t_disc	*a;
	t_disc	**b;
	t_disc	*current;
	char	*op;
	
	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	if (a == NULL)
		return (1);
	b = malloc(sizeof(t_disc *));
	if (!b)
		ft_error(ERROR);
	*b = NULL;
	current = a;
	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		if (!is_valid_op(op))
			ft_error(ERROR);
		exec_op_noprint(&a, b, op);
		free(op);
	}
	if (!*b && is_sorted(a))
		ft_printf(GRN "OK\n" RESET);
	else
		ft_printf(RED "KO\n" RESET);
	free_disc(a);
	free(b);
	return (0);
}
