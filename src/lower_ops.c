/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:49:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/13 15:44:29 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_disc **a)
{
	t_disc	*first;
	t_disc	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	second->index = 0;
	first->index = 1;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	push(t_disc **a, t_disc **b)
{
	t_disc	*head;
	t_disc	*current;	

	if (!a || !b || !*a)
		return ;
	if ((*a)->stack == 'a')
		(*a)->stack = 'b';
	else
		(*a)->stack = 'a';
	if ((*a)->next == NULL)
	{
		ft_discadd_front(b, *a);
		*a = NULL;
		return ;
	}
	head = (*a)->next;
	current = head;
	while (current != NULL)
	{
		current->index--;
		current = current->next;
	}
	ft_discadd_front(b, *a);
	*a = head;
}

void	rotate(t_disc **a)
{
	t_disc	*head;
	t_disc	*current;
	int		i;

	if (!a || !*a || !(*a)->next)
		return ;
	head = (*a)->next;
	ft_disclast(*a)->next = *a;
	(*a)->next = NULL;
	*a = head;
	current = head;
	i = 0;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

void	reverse_rotate(t_disc	**a)
{
	t_disc	*head;
	t_disc	*penultimate;
	t_disc	*current;
	int		i;

	if (!a | !*a || !(*a)->next)
		return ;
	head = ft_disclast(*a);
	penultimate = *a;
	while (penultimate->next != head)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	head->next = *a;
	*a = head;
	current = head;
	i = 0;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}
