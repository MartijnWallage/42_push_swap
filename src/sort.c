/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 15:10:40 by mwallage         ###   ########.fr       */
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

int	is_sorted(t_list *a)
{
	if (is_ascending(a))
		return (1);
	return (0);
}

char	*sort_stack(t_list **a, t_list **b, char *instructions)
{
	char	*best;
	t_table	scores;

	if (score(*a, *b) == 0)
		return (instructions);
	calculate_scores(a, b, &scores);
	best = best_op(&scores);
	if (best == NULL)
		return (instructions);
	instructions = ft_strjoin(instructions, best);
	if (instructions == NULL)
		return (NULL);
	display_stacks(*a, *b);
	ft_printf("\nScore: %d\n", score(*a, *b));
	ft_printf("Best operation: %s\n", best);
	exec_op(a, b, best);
	instructions = sort_stack(a, b, instructions);
	return (instructions);
}