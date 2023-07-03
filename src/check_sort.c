/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/03 15:03:42 by mwallage         ###   ########.fr       */
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

int	is_sorted(t_disc *disc)
{
	if (is_ascending(disc))
		return (1);
	return (0);
}

int ascending(t_disc *a)
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
	if (nfails)
		nfails--;
	return (nfails);
}

int descending(t_disc *b)
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
	if (nfails)
		nfails--;
	return (nfails);
}

int	disc_sorted(t_disc *disc, char which_stack)
{
	if (!disc)
		return (0);
	if (which_stack == 'a')
		return (ascending(disc));
	else
		return (descending(disc));
}