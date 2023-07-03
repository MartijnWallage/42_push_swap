/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:49:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/03 16:33:00 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*move_to_front(t_disc **a, char stack, int index)
{
	char	*instructions;
	char	*temp;
	char	*op;
	int		len;
	int		i;

	instructions = malloc(1);
	if (!instructions)
		return (NULL);
	*instructions = 0;
	len = disc_size(*a);
	i = -1;
	if (index <= len - index)
	{
		if (stack == 'a')
			op = ft_strdup(RA);
		else
			op = ft_strdup(RB);
		while (++i < index)
		{
			rotate(a);
			temp = instructions;
			instructions = ft_strjoin(op, instructions);
			free(temp);
		}
		free(op);
	}
	else
	{
		if (stack == 'a')
			op = ft_strdup(RRA);
		else
			op = ft_strdup(RRB);
		while (++i < len - index)
		{
			reverse_rotate(a);
			temp = instructions;
			instructions = ft_strjoin(op, instructions);
			free(temp);
		}
		free(op);
	}
	return (instructions);
}

void	exec_op(t_disc **a, t_disc **b, char *op)
{
	if (op == NULL || !a || !b)
		return ;
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
