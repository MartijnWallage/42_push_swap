/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:12:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/07 18:57:50 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		disc_size(t_disc *disc)
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

void	*free_disc(t_disc *disc)
{
	t_disc	*current;
	t_disc	*next;
	
	if (!disc)
		return (NULL);
	current = disc;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (NULL);
}

void	ft_discadd_back(t_disc **disc, t_disc *new)
{
	t_disc	*current;

	if (*disc == NULL)
	{
		*disc = new;
		new->index = 0;
	}
	else
	{
		current = *disc;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->index = current->index + 1;
	}
}

t_disc	*ft_disclast(t_disc *disc)
{
	if (disc == NULL)
		return (NULL);
	while (disc->next != NULL)
		disc = disc->next;
	return (disc);
}

void	ft_discadd_front(t_disc **disc, t_disc *new)
{
	t_disc	*current;
	
	if (disc == NULL || new == NULL)
		return ;
	new->next = *disc;
	*disc = new;
	new->index = 0;
	current = new->next;
	while (current)
	{
		current->index++;
		current = current->next;
	}
}

t_disc	*ft_discnew(int nbr)
{
	t_disc	*newnode;

	newnode = malloc(sizeof(t_disc));
	if (newnode == NULL)
		return (NULL);
	newnode->rank = nbr;
	newnode->index = 0;
	newnode->stack = 'a';
	newnode->cost = -1;
	newnode->next = NULL;
	return (newnode);
}
