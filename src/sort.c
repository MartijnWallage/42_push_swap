/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/12 16:42:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rr_to_front(t_disc **a, int target_a, t_disc **b, int target_b)
{
	int	i;
	int	a_revrot;
	int	b_revrot;

	a_revrot = disc_size(*a) - target_a;
	b_revrot = disc_size(*b) - target_b;
	i = -1;
	while (++i < min(a_revrot, b_revrot))
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
	while (++i < min(target_a, target_b))
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

	a_revrot = disc_size(*a) - target_a;
	b_revrot = disc_size(*b) - target_b;
	if (min(max(a_revrot, b_revrot), max(target_a, target_b))
		> min(target_a, a_revrot) + min(target_b, b_revrot))
	{
		move_to_front(a, target_a);
		move_to_front(b, target_b);
	}
	else if (max(a_revrot, b_revrot) < max(target_a, target_b))
		rr_to_front(a, target_a, b, target_b);
	else
		r_to_front(a, target_a, b, target_b);
}

static void	smart_push(t_disc **a, t_disc **b)
{
	t_disc	*cheapest;
	int		insert;

	cheapest = find_cheapest(*a, *b);
	insert = find_place(*b, cheapest->rank);
	double_move_to_front(a, cheapest->index, b, insert);
	push(a, b);
	ft_printf("p%c\n", (*b)->stack);
}

void	sort_stack(t_disc **a, t_disc **b)
{
	if (!*b && is_sorted(*a))
		return ;
	if (!*b && wrong_pairs(*a) == 0)
		move_to_front(a, get_index(*a, 0));
	else if (disc_size(*a) == 3 && wrong_pairs(*a))
	{
		exec_op(a, b, "sa");
		sort_stack(a, b);
	}
	else if (*b && wrong_pairs(*a) == 0 && wrong_pairs(*b) == 0)
	{
		smart_push(b, a);
		sort_stack(a, b);
	}
	else if (wrong_pairs(*a))
	{
		smart_push(a, b);
		sort_stack(a, b);
	}
}
