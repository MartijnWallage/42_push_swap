/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/10 14:21:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	double_move_to_front(t_disc **a, int target_a, t_disc **b, int target_b)
{
	int		a_revrot;
	int		b_revrot;
	int		rrr;
	int		rr;
	int		i;
	
	a_revrot = disc_size(*a) - target_a;
	b_revrot = disc_size(*b) - target_b;
	rrr = min(a_revrot, b_revrot);
	rr = min(target_a, target_b);
	if (min(max(a_revrot, b_revrot), max(target_a, target_b))
		> min(target_a, a_revrot) + min(target_b, b_revrot))
	{
		move_to_front(a, target_a);
		move_to_front(b, target_b);
		return ;
	}
	if (max(a_revrot, b_revrot) < max(target_a, target_b))
	{
		i = -1;
		while (++i < rrr)
			exec_op(a, b, "rrr");
		while (i < a_revrot)
		{
			exec_op(a, b, "rra");
			i++;
		}
		while (i < b_revrot)
		{
			exec_op(a, b, "rrb");
			i++;
		}
	}
	else
	{
		i = -1;
		while (++i < rr)
			exec_op(a, b, "rr");
		while (i < target_a)
		{
			exec_op(a, b, "ra");
			i++;
		}
		while (i < target_b)
		{
			exec_op(a, b, "rb");
			i++;
		}
	}
}

void	sort_stack(t_disc **a, t_disc **b)
{
	t_disc	*cheapest;
	int	insert;

	if (!*b && is_sorted(*a))
		return ;
	if (!*b && wrong_pairs(*a) == 0)
	{
		move_to_front(a, get_index(*a, 0));
		return ;
	}
	if (disc_size(*a) == 3 && wrong_pairs(*a))
	{
		exec_op(a, b, "sa");
		sort_stack(a, b);
		return ;
	}
	if (*b && wrong_pairs(*a) == 0 && wrong_pairs(*b) == 0)
	{
		cheapest = find_cheapest(*b, *a);
		insert = find_place(*a, cheapest->rank);
		double_move_to_front(a, insert, b, cheapest->index);
		exec_op(a, b, "pa");
		sort_stack(a, b);
		return ;
	}
	if (wrong_pairs(*a))
	{
		cheapest = find_cheapest(*a, *b);
		insert = find_place(*b, cheapest->rank);
		double_move_to_front(a, cheapest->index, b, insert);
		exec_op(a, b, "pb");
		sort_stack(a, b);
	}
}
