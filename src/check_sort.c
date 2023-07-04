/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/04 17:26:44 by mwallage         ###   ########.fr       */
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

int descending_pairs(t_disc *a)
{
	int		nfails;
	t_disc	*current;

	nfails = 0;
	current = a;
	while (current && current->next)
	{
		if (current->rank > current->next->rank)
			nfails++;
		current = current->next;
	}
	if (current && current->rank > a->rank)
		nfails++;
	if (nfails == 0)
		nfails++;
	return (nfails);
}

int ascending_pairs(t_disc *b)
{
	int		nfails;
	t_disc	*current;

	nfails = 0;
	current = b;
	while (current && current->next)
	{
		if (current->rank < current->next->rank)
			nfails++;
		current = current->next;
	}
	if (current && current->rank < b->rank)
		nfails++;
	if (nfails == 0)
		nfails++;
	return (nfails);
}

int	is_sorted(t_disc *disc)
{
	if (disc->stack == 'a')
		return (is_ascending(disc));
	else
		return (descending_pairs(disc) == 1);
}

int	discsort_fails(t_disc *disc)
{
	if (!disc)
		return (0);
	if (disc->stack == 'a')
		return (descending_pairs(disc) - 1);
	else
		return (ascending_pairs(disc) - 1);
}