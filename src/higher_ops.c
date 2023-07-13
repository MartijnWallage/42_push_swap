/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:49:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/13 15:33:03 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rr_to_front(t_disc **a, int target_a, t_disc **b, int target_b)
{
	int	i;
	int	a_revrot;
	int	b_revrot;

	a_revrot = disclen(*a) - target_a;
	b_revrot = disclen(*b) - target_b;
	i = -1;
	while (++i < ft_min(a_revrot, b_revrot))
		exec_op(a, b, "rrr");
	while (i < a_revrot)
	{
		reverse_rotate(a);
		ft_printf("rr%c\n", (*a)->stack);
		i++;
	}
	while (i < b_revrot)
	{
		reverse_rotate(b);
		ft_printf("rr%c\n", (*b)->stack);
		i++;
	}
}

static void	r_to_front(t_disc **a, int target_a, t_disc **b, int target_b)
{
	int	i;

	i = -1;
	while (++i < ft_min(target_a, target_b))
		exec_op(a, b, "rr");
	while (i < target_a)
	{
		rotate(a);
		ft_printf("r%c\n", (*a)->stack);
		i++;
	}
	while (i < target_b)
	{
		rotate(b);
		ft_printf("r%c\n", (*b)->stack);
		i++;
	}
}

void	double_move_to_front(t_disc **a, int target_a, t_disc **b, int target_b)
{
	int		a_revrot;
	int		b_revrot;

	a_revrot = disclen(*a) - target_a;
	b_revrot = disclen(*b) - target_b;
	if (ft_min(ft_max(a_revrot, b_revrot), ft_max(target_a, target_b))
		> ft_min(target_a, a_revrot) + ft_min(target_b, b_revrot))
	{
		move_to_front(a, target_a);
		move_to_front(b, target_b);
	}
	else if (ft_max(a_revrot, b_revrot) < ft_max(target_a, target_b))
		rr_to_front(a, target_a, b, target_b);
	else
		r_to_front(a, target_a, b, target_b);
}

void	move_to_front(t_disc **disc, int index)
{
	int		len;
	int		i;

	if (!disc || !*disc || index == 0)
		return ;
	len = disclen(*disc);
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
