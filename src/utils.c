/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/29 16:28:55 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	opposite_letter(char letter)
{
	if (letter == 'a')
		return ('b');
	else if (letter == 'b')
		return ('a');
	if ((letter == 'r') || (letter == 's') || letter == '\0')
		return (letter);
	return (0);
}

char	*reverse_op(char *last)
{
	char	*op;

	if (last == NULL)
		return (NULL);
	op = malloc(4);
	if (op == NULL)
		return (NULL);
	op[0] = last[0];
	op[2] = 0;
	op[3] = 0;
	if (last[0] == 's')
		op[1] = last[1];
	else if (last[0] == 'p')
		op[1] = opposite_letter(last[1]);
	else if (last[0] == 'r' && last[1] == 'r')
		op[1] = last[2];
	else if (last[0] == 'r')
	{
		op[1] = 'r';
		op[2] = last[1];
	}
	return (op);
}

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