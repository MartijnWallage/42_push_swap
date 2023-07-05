/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:49:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/05 16:20:12 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	try_swap(t_disc **a)
{
	int	before;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	before = wrong_pairs(*a);
	swap(a);
	if (wrong_pairs(*a) < before)
		return (1);
	swap(a);
	return (0);
}

int	try_push(t_disc **a, t_disc **b)
{
	if (!a || !b || !*a)
		return (0);
	push(a, b);
	if (wrong_pairs(*b) == 0)
		return (1);
	push(b, a);
	return (0);
}

int	movetofront_cost(t_disc *disc, int target)
{
	int	len;

	len = disc_size(disc);
	if (len - target < target)
		return (len - target);
	else
		return (target);
}

int	try_rotate(t_disc **a, int target)
{
	int	before;

	if (!a || !*a || !(*a)->next)
		return (0);
	before = movetofront_cost(*a, target);
	rotate(a);
	if (movetofront_cost(*a, target) < before)
		return (1);
	reverse_rotate(a);
	return (0);
}

int	try_reverse_rotate(t_disc **a, int target)
{
	int	before;
	
	if (!a | !*a || !(*a)->next)
		return (0);
	before = movetofront_cost(*a, target);
	reverse_rotate(a);
	if (movetofront_cost(*a, target) < before)
		return (1);
	rotate(a);
	return (0);
}
