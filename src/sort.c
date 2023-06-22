/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/18 19:43:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_ascending(t_list *stack)
{
	int	first;
	int	second;
	
	while (stack && stack->next)
	{
		first = *(int *)(stack->content);
		second = *(int *)(stack->next->content);
		if (first > second)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_list *a, t_list *b)
{
	if (b == NULL && is_ascending(a))
		return (1);
	return (0);
}