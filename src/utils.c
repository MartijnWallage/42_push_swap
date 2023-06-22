/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:48 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/22 19:02:41 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack->content);
		free(stack);
		stack = temp;
	}
	return (NULL);
}

t_list	*get_args(int argc, char **argv)
{
	int		i;
	int		*content;
	t_list	*stack;
	t_list	*new_node;

	stack = NULL;
	i = 0;
	while (++i < argc)
	{
		content = malloc(sizeof(int));
		if (content == NULL)
			return (free_stack(stack));
		*content = ft_atoi(argv[i]);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
			return (free_stack(stack));
		ft_lstadd_back(&stack, new_node);
	}
	return (stack);
}

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