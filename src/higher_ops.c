/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:49:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/12 17:31:00 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_to_front(t_disc **disc, int index)
{
	int		len;
	int		i;

	if (!disc || !*disc || index == 0)
		return ;
	len = disc_size(*disc);
	i = -1;
	if (index <= len - index)
	{
		while (++i < index)
		{
			rotate(disc);
			ft_printf("r%c\n", (*disc)->stack);
		}
	}
	else
	{
		while (++i < len - index)
		{
			reverse_rotate(disc);
			ft_printf("rr%c\n", (*disc)->stack);
		}
	}
}

void	exec_op(t_disc **a, t_disc **b, const char *op)
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
	ft_printf("%s\n", op);
}
