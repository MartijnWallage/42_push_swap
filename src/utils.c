/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/10 15:12:24 by mwallage         ###   ########.fr       */
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

t_disc	*get_lowest_rank(t_disc *disc)
{
	t_disc	*current;
	t_disc	*lowest;

	if (!disc)
		return (NULL);
	current = disc;
	lowest = current;
	while (current)
	{
		if (current->rank < lowest->rank)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_disc	*get_highest_rank(t_disc *disc)
{
	t_disc	*current;
	t_disc	*highest;

	if (!disc)
		return (NULL);
	current = disc;
	highest = current;
	while (current)
	{
		if (current->rank > highest->rank)
			highest = current;
		current = current->next;
	}
	return (highest);
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

t_disc	*get_by_index(t_disc *disc, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		disc = disc->next;
	return (disc);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
