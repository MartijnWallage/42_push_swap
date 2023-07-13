/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/13 15:46:01 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_disc	*previous(t_disc *head, t_disc *node)
{
	t_disc	*current;

	if (head == node)
		return (disclast(head));
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

t_disc	*get_lowest(t_disc *disc)
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

t_disc	*get_highest(t_disc *disc)
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

int	disclen(t_disc *disc)
{
	int		size;
	t_disc	*current;

	current = disc;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}