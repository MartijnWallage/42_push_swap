/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/03 16:12:16 by mwallage         ###   ########.fr       */
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

int	get_lowest_rank(t_disc *a)
{
	t_disc	*current;
	int		lowest_rank;

	if (!a)
		return (-1);
	current = a;
	lowest_rank = current->rank;
	while (current)
	{
		if (current->rank < lowest_rank)
			lowest_rank = current->rank;
		current = current->next;
	}
	return (lowest_rank);
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

int	is_sorted_pair(t_disc *disc, char stack, t_disc *node, t_disc *next_node)
{
	int	lowest_rank;

	if (!disc || !node || !next_node || node == next_node)
		return (1);
	lowest_rank = get_lowest_rank(disc);
	next_node = next(disc, node);
	if (node->rank == lowest_rank)
		return (stack == 'a');
	if (next_node->rank == lowest_rank)
		return (stack == 'b');
	if (node->rank < next_node->rank)
		return (stack == 'a');
	else
		return (stack == 'b');
}

int		first_wrong_pair(t_disc *a, char stack)
{
	t_disc	*current;
	int		lowest_rank;
	
	if (!a || !(a->next))
		return (-1);
	current = a;
	lowest_rank = get_lowest_rank(a);
	while (current)
	{
		if ((stack == 'a' && next(a, current)->rank != lowest_rank && current->rank > next(a, current)->rank)
		|| (stack == 'b' && current->rank != lowest_rank && current->rank < next(a, current)->rank))
			return (current->index);
		current = current->next;
	}
	return (-1);
}
