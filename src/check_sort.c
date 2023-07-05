/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/05 17:07:23 by mwallage         ###   ########.fr       */
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