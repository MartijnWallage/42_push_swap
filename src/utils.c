/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/04 15:59:49 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_disc	*previous(t_disc *head, t_disc *node)
{
	t_disc	*current;

	if (head == node)
		return (ft_disclast(head));
	current = head;
	while (current)
	{
		if (current->next == node)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_disc	*next(t_disc *head, t_disc *node)
{
	if (node->next == NULL)
		return (head);
	else
		return (node->next);
}

int	get_lowest_rank(t_disc *disc)
{
	t_disc	*current;
	int		lowest_rank;

	if (!disc)
		return (-1);
	current = disc;
	lowest_rank = current->rank;
	while (current)
	{
		if (current->rank < lowest_rank)
			lowest_rank = current->rank;
		current = current->next;
	}
	return (lowest_rank);
}

int	get_highest_rank(t_disc *disc)
{
	t_disc	*current;
	int		highest_rank;

	if (!disc)
		return (-1);
	current = disc;
	highest_rank = current->rank;
	while (current)
	{
		if (current->rank > highest_rank)
			highest_rank = current->rank;
		current = current->next;
	}
	return (highest_rank);
}
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

int	is_sorted_pair(t_disc *disc, t_disc *node, t_disc *next_node)
{
	int	lowest_rank;

	if (!disc || !node || !next_node || node == next_node)
		return (1);
	lowest_rank = get_lowest_rank(disc);
	next_node = next(disc, node);
	if (node->rank == lowest_rank)
		return (disc->stack == 'a');
	if (next_node->rank == lowest_rank)
		return (disc->stack == 'b');
	if (node->rank < next_node->rank)
		return (disc->stack == 'a');
	else
		return (disc->stack == 'b');
}

int		first_wrong_pair(t_disc *a)
{
	t_disc	*current;
	int		lowest_rank;
	
	if (!a || !(a->next))
		return (-1);
	current = a;
	lowest_rank = get_lowest_rank(a);
	while (current)
	{
		if ((a->stack == 'a' && next(a, current)->rank != lowest_rank && current->rank > next(a, current)->rank)
		|| (a->stack == 'b' && current->rank != lowest_rank && current->rank < next(a, current)->rank))
			return (current->index);
		current = current->next;
	}
	return (-1);
}
