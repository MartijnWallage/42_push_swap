/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/30 16:23:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_disc	*get_prev_node(t_disc *head, t_disc *node)
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