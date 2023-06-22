/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/22 19:41:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*try_op(t_list **a, t_list **b, int depth, char *op, char *last_op)
{
	char	*instructions;

	if (ft_strncmp(op, reverse_op(last_op), 3) == 0)
		return (NULL);
	exec_op(a, b, op);
	instructions = sort_stacks(a, b, depth - 1, op);
	if (instructions)
	{
		ft_printf(GRN "*********************\nLevel %d: Tried %s" RESET, depth, op);
		display_stacks(*a, *b);
	}
	else
	{
		ft_printf(RED "*********************\nLevel %d: Tried %s" RESET, depth, op);
		display_stacks(*a, *b);
	}
	if (instructions)
		return (ft_strjoin(op, instructions));
	exec_op(a, b, reverse_op(op));
	return (NULL);
}

char	*sort_stacks(t_list **a, t_list **b, int depth, char *last_op)
{
	char	*instructions;
	
	instructions = NULL;
	if (is_sorted(*a, *b))
	{
		instructions = malloc(1);
		*instructions = '\0';
		return (instructions);
	}
	if (depth == 0)
		return (NULL);
	if (*a && *b && (*a)->next && (*b)->next)
	{
		instructions = try_op(a, b, depth, "ss\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "rr\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "rrr\n", last_op);
		if (instructions)
			return (instructions);
	}
	if (*a && (*a)->next)
	{
		instructions = try_op(a, b, depth, "sa\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "ra\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "rra\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "pb\n", last_op);
		if (instructions)
			return (instructions);
	}
	if (*b != NULL)
	{
		instructions = try_op(a, b, depth, "sb\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "rb\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "rrb\n", last_op);
		if (instructions)
			return (instructions);
		instructions = try_op(a, b, depth, "pa\n", last_op);
		if (instructions)
			return (instructions);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*instructions;
	int		depth;
	
	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	if (a == NULL)
		return (1);
	b = NULL;
	ft_printf("\nInit a and b\n");
	display_stacks(a, b);
	depth = 0;
	instructions = NULL;
	while (!is_sorted(a, b))
	{
		if (instructions != NULL)
			free(instructions);
		instructions = NULL;
		instructions = sort_stacks(&a, &b, depth, "");
		depth++;
	}
	display_stacks(a, b);
	display_instructions(instructions);
	free_stack(a);
	if (instructions)
		free(instructions);
	return (0);
}
