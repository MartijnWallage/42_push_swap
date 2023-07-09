/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/09 19:31:50 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_place(t_disc *disc, int target)
{
	t_disc	*current;
	t_disc	*highest;
	t_disc	*lowest;
	t_disc	*return_node;

	if (!disc)
		return (0);
	highest = disc;
	current = disc;
	lowest = disc;
	return_node = NULL;
	if (disc->stack == 'b')
	{
		while (current)
		{
			if (current->rank > highest->rank)
				highest = current;
			if (current->rank < target && (!return_node || current->rank > return_node->rank))
				return_node = current;
			current = current->next;
		}
		if (!return_node)
			return_node = highest;
	}
	if (disc->stack == 'a')
	{
		while (current)
		{
			if (current->rank < lowest->rank)
				lowest = current;
			if (current->rank > target && (!return_node || current->rank < return_node->rank))
				return_node = current;
			current = current->next;
		}
		if (!return_node)
			return_node = lowest;
	}
	return (return_node->index);
}

void	calc_pushcosts(t_disc *a, t_disc *b)
{
	t_disc	*current;
	int		target;
	int		size_a;
	int		size_b;
	int		temp;
	
	if (!a)
		return ;
	current = a;
	size_a = disc_size(a);
	size_b = disc_size(b);
	while (current)
	{
		target = find_place(b, current->rank);
		current->cost = max(current->index, target);
		temp = max(size_a - current->index, size_b - target);
		current->cost = min(current->cost, temp);
		current->cost = 1 + min(current->cost,
			min(current->index, size_a - current->index) + min(target, size_b - target));
		current = current->next;
	}
}

t_disc	*find_cheapest(t_disc *disc)
{
	t_disc	*current;
	t_disc	*cheapest;
	
	current = disc;
	cheapest = NULL;
	while (current)
	{
		if (current->rank != 0 && (!cheapest || current->cost < cheapest->cost))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
