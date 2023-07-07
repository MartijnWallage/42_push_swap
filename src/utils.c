/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/07 18:22:15 by mwallage         ###   ########.fr       */
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
