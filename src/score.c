/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:31:17 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 19:05:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	score(t_disc *a, t_disc *b)
{
	int	result;
	t_disc	*current;

	result = 0;
	//	Low cost for the first two being out of order
	if (a && a->next && a->rank > a->next->rank)
		result++;
	if (b && b->next && b->rank < b->next->rank)
		result++;
	//	Higher cost for anything later being out of order	
	current = NULL;
	if (a && a->next)
		current = a->next;
	while (current && current->next)
	{
		if (current->rank > current->next->rank)
			result += 10;
		current = current->next;
	}
	if (b && a && b->rank > a->rank)
		result += 2;
	current = NULL;
	if (b)
		result++;
	if (b && b->next)
		current = b->next;
	while (current)
	{
		result += 1;
		if (current->next && current->rank < current->next->rank)
			result += 10;
		current = current->next;
	}
	return (result);
}

void	calculate_scores(t_disc **a, t_disc **b, t_table *scores)
{		
	exec_op(a, b, "sa");
	scores->sa = score(*a, *b);
	exec_op(a, b, "sa");

	exec_op(a, b, "sb");
	scores->sb = score(*a, *b);
	exec_op(a, b, "sb");
	
	exec_op(a, b, "ss");
	scores->ss = score(*a, *b);
	exec_op(a, b, "ss");

	if (!*b)
		scores->pa = score(*a, *b);
	else
	{
		exec_op(a, b, "pa");
		scores->pa = score(*a, *b);
		exec_op(a, b, "pb");
	}

	if (!*a)
		scores->pb = score(*a, *b);
	else
	{
		exec_op(a, b, "pb");
		scores->pb = score(*a, *b);
		exec_op(a, b, "pa");
	}
	
	exec_op(a, b, "ra");
	scores->ra = score(*a, *b);
	exec_op(a, b, "rra");

	exec_op(a, b, "rb");
	scores->rb = score(*a, *b);
	exec_op(a, b, "rrb");

	exec_op(a, b, "rr");
	scores->rr = score(*a, *b);
	exec_op(a, b, "rrr");

	exec_op(a, b, "rra");
	scores->rra = score(*a, *b);
	exec_op(a, b, "ra");

	exec_op(a, b, "rrb");
	scores->rrb = score(*a, *b);
	exec_op(a, b, "rb");

	exec_op(a, b, "rrr");
	scores->rrr = score(*a, *b);
	exec_op(a, b, "rr");
}

char	*best_op(t_table *scores)
{
	int		min;
	char	*op;

	op = malloc(5);
	if (op == NULL)
		return (NULL);
	min = scores->sa;
	op = "sa\n";
	if (scores->sb < min)
	{
		min = scores->sb;
		op = "sb\n";
	}
	if (scores->ss < min)
	{
		min = scores->ss;
		op = "ss\n";
	}
	if (scores->pa < min)
	{
		min = scores->pa;
		op = "pa\n";
	}
	if (scores->pb < min)
	{
		min = scores->pb;
		op = "pb\n";
	}
	if (scores->ra < min)
	{
		min = scores->ra;
		op = "ra\n";
	}
	if (scores->rb < min)
	{
		min = scores->rb;
		op = "rb\n";
	}
	if (scores->rr < min)
	{
		min = scores->rr;
		op = "rr\n";
	}
	if (scores->rra < min)
	{
		min = scores->rra;
		op = "rra\n";
	}
	if (scores->rrb < min)
	{
		min = scores->rrb;
		op = "rrb\n";
	}
	if (scores->rrr < min)
	{
		min = scores->rrr;
		op = "rrr\n";
	}
	return (op);
}
