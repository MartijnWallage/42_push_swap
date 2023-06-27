/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:12:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 19:14:52 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*free_disc(t_disc *disc)
{
	t_disc	*temp;

	if (!disc)
		return (NULL);
	disc = disc->next;
	while (disc->index !=0)
	{
		temp = disc->next;
		free(disc);
		disc = temp;
	}
	free(disc);
	return (NULL);
}

t_disc	*ft_disclast(t_disc *disc)
{
	if (disc == NULL)
		return (NULL);
	while (disc->next->index != 0)
		disc = disc->next;
	return (disc);
}

void	ft_discadd_front(t_disc **disc, t_disc *new)
{
	t_disc	*current;
	t_disc	*last;
	
	if (disc == NULL || new == NULL)
		return ;
	new->next = *disc;
	last = ft_disclast(*disc);
	new->previous = last;
	last->next = new;
	new->index = 0;
	current = *disc;
	while (current != new)
	{
		current->index++;
		current = current->next;
	}
	*disc = new;
}

t_disc	*ft_discnew(int nbr)
{
	t_disc	*newnode;

	newnode = malloc(sizeof(t_disc));
	if (newnode == NULL)
		return (NULL);
	newnode->rank = nbr;
	newnode->index = 0;
	newnode->previous = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	ft_discadd_back(t_disc **disc, t_disc *new)
{
	t_disc	*current;

	if (*disc == NULL)
	{
		*disc = new;
		(*disc)->index = 0;
		(*disc)->next = *disc;
		(*disc)->previous = *disc;
	}
	else
	{
		current = *disc;
		while (current->next->index != 0)
			current = current->next;
		current->next = new;
		new->previous = current;
		(*disc)->previous = new;	
		new->next = *disc;
		new->index = current->index + 1;
	}
}

t_disc	*get_args(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_disc	*disc;
	t_disc	*new_node;

	disc = NULL;
	i = 0;
	while (++i < argc)
	{
		nbr = ft_atoi(argv[i]);
		new_node = ft_discnew(nbr);
		if (new_node == NULL)
			return (free_disc(disc));
		ft_discadd_back(&disc, new_node);
	}
	return (disc);
}
