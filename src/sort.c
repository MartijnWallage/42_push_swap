/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/13 15:21:54 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_index(t_disc *disc, int rank)
{
	t_disc	*current;

	current = disc;
	while (current)
	{
		if (current->rank == rank)
			return (current->index);
		current = current->next;
	}
	return (-1);
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
	else if (disclen(*a) == 3 && wrong_pairs(*a))
	{
		exec_op(a, b, "sa");
		sort_stack(a, b);
	}
	else if (*b && !wrong_pairs(*a) && !wrong_pairs(*b))
	{
		smart_push(b, a);
		sort_stack(a, b);
	}
	else
	{
		smart_push(a, b);
		sort_stack(a, b);
	}
}
