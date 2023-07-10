/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/10 18:16:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_place(t_disc *disc, int target)
{
	t_disc	*current;
	t_disc	*return_node;

	if (!disc)
		return (0);
	current = disc;
	return_node = NULL;
	while (current)
	{
		if (disc->stack == 'b' && (current->rank < target && (!return_node
					|| current->rank > return_node->rank)))
			return_node = current;
		if (disc->stack == 'a' && (current->rank > target && (!return_node
					|| current->rank < return_node->rank)))
			return_node = current;
		current = current->next;
	}
	if (!return_node && disc->stack == 'a')
		return_node = get_lowest(disc);
	if (!return_node && disc->stack == 'b')
		return_node = get_highest(disc);
	return (return_node->index);
}

t_disc	*find_cheapest(t_disc *a, t_disc *b)
{
	t_disc	*current;
	t_disc	*cheapest;
	int		target;
	int		size_a;
	int		size_b;

	if (!a)
		return (NULL);
	current = a;
	cheapest = current;
	size_a = disc_size(a);
	size_b = disc_size(b);
	while (current)
	{
		target = find_place(b, current->rank);
		current->cost = min(max(current->index, target),
				max(size_a - current->index, size_b - target));
		current->cost = 1 + min(current->cost,
				min(current->index, size_a - current->index)
				+ min(target, size_b - target));
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
