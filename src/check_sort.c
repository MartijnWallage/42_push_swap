/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/10 18:12:17 by mwallage         ###   ########.fr       */
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

int wrong_pairs(t_disc *disc)
{
	int		nfails;
	t_disc	*current;

	nfails = 0;
	current = disc;
	while (current)
	{
		if (disc->stack == 'a' && current->rank > next(disc, current)->rank)
			nfails++;
		else if (disc->stack == 'b' && current->rank < next(disc, current)->rank)
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

int	is_sorted_pair(t_disc *disc, t_disc *node)
{
	t_disc	*next_node;

	if (!disc || !node)
		return (1);
	next_node = next(disc, node);
	if (disc->stack == 'a' && next_node->rank == 0)
		return (1);
	if (disc->stack == 'b' && next_node->rank == get_highest(disc)->rank)
		return (1);
	if (disc->stack == 'a' && node->rank < next_node->rank)
		return (1);
	if (disc->stack == 'b' && node->rank > next_node->rank)
		return (1);
	return (0);
}

int		first_wrong_pair(t_disc *a)
{
	t_disc	*current;
	int		lowest_rank;
	
	if (!a || !(a->next))
		return (-1);
	current = a;
	lowest_rank = get_lowest(a)->rank;
	while (current)
	{
		if ((a->stack == 'a' && next(a, current)->rank != lowest_rank && current->rank > next(a, current)->rank)
		|| (a->stack == 'b' && current->rank != lowest_rank && current->rank < next(a, current)->rank))
			return (current->index);
		current = current->next;
	}
	return (-1);
}
