/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/13 15:45:48 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_ascending(t_disc *disc)
{
	int	first;
	int	second;

	while (disc && disc->next)
	{
		first = disc->rank;
		second = disc->next->rank;
		if (first > second)
			return (0);
		disc = disc->next;
	}
	return (1);
}

int	wrong_pairs(t_disc *disc)
{
	int		nfails;
	t_disc	*current;

	nfails = 0;
	current = disc;
	while (current)
	{
		if (disc->stack == 'a' && current->rank > next(disc, current)->rank)
			nfails++;
		else if (disc->stack == 'b'
			&& current->rank < next(disc, current)->rank)
			nfails++;
		current = current->next;
	}
	if (nfails > 0)
		nfails--;
	return (nfails);
}

int	is_sorted(t_disc *disc)
{
	if (disc->stack == 'a')
		return (is_ascending(disc));
	else
		return (wrong_pairs(disc) == 0);
}

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
		current->cost = ft_min(ft_max(current->index, target),
				ft_max(size_a - current->index, size_b - target));
		current->cost = 1 + ft_min(current->cost,
				ft_min(current->index, size_a - current->index)
				+ ft_min(target, size_b - target));
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
