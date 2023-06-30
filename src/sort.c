/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/30 16:52:18 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_ascending(t_disc *stack)
{
	int	first;
	int	second;
	
	while (stack && stack->next)
	{
		first = stack->rank;
		second = stack->next->rank;
		if (first > second)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_disc *a)
{
	if (is_ascending(a))
		return (1);
	return (0);
}

int ascending(t_disc *a)
{
	int		nfails;
	t_disc	*current;

	nfails = 0;
	current = a;
	while (current && current->next)
	{
		if (current->rank > current->next->rank)
			nfails++;
		current = current->next;
	}
	if (current && current->rank > a->rank)
		nfails++;
	if (nfails)
		nfails--;
	return (nfails);
}

int descending(t_disc *b)
{
	int		nfails;
	t_disc	*current;

	nfails = 0;
	current = b;
	while (current && current->next)
	{
		if (current->rank < current->next->rank)
			nfails++;
		current = current->next;
	}
	if (current && current->rank < b->rank)
		nfails++;
	if (nfails)
		nfails--;
	return (nfails);
}

int	disc_sorted(t_disc *disc, int stack)
{
	if (!disc)
		return (0);
	if (stack == 0)
		return (ascending(disc));
	else
		return (descending(disc));
}

int	*update_ops(t_disc *a, t_disc *b)
{
	int	*result;
	int	i;

	result = malloc(sizeof(int) * 11);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < 11)
		result[i] = 0;
	if (a && a->next && a->rank > a->next->rank)
	{
		if (!a->next->next || a->rank < a->next->next->rank)
			result[SA] = 1;
		else
		{
			result[RA] = 1;
			result[PB] = 1;
		}
	}
	if (b)
	{
		if (b->next && b->rank < b->next->rank)
			result[SB] = 1;
		if (b->next && b->next->next && b->rank < b->next->next->rank)
			result[SB] = 0;
		if (result[SB])
			result[PA] = 0;
		else
			result[PA] = 1;
	}
	if (disc_sorted(a, 0) == 0)
	{
		result[SA] = 0;
		result[SS] = 0;
		result[PB] = 0;
		result[RA] = 0;
		result[RRA] = 1;
	}
	else if (a && a->next && a->rank > a->next->rank)
		result[SA] = 1;
	if (b && b->next && disc_sorted(b, 1) == 0)
	{
		result[SB] = 0;
		result[SS] = 0;
		result[PA] = 0;
		result[RB] = 0;
		result[RRB] = 1;
	}
	else if (b && b->next && b->rank < b->next->rank)
		result[SB] = 1;
	if (result[RA] && result[RB])
	{
		result[RR] = 1;
		result[RA] = 0;
		result[RB] = 0;
	}
	if (result[RRA] && result[RRB])
	{
		result[RRR] = 1;
		result[RRA] = 0;
		result[RRB] = 0;
	}
	if (result[SA] && result[SB])
	{
		result[SS] = 1;
		result[SA] = 0;
		result[SB] = 0;
	}
	return (result);	
}

char	*op_name(int i)
{
	if (i == 0)
		return ("sa");
	if (i == 1)
		return ("sb");
	if (i == 2)
		return ("ss");
	if (i == 3)
		return ("pa");
	if (i == 4)
		return ("pb");
	if (i == 5)
		return ("ra");
	if (i == 6)
		return ("rb");
	if (i == 7)
		return ("rr");
	if (i == 8)
		return ("rra");
	if (i == 9)
		return ("rrb");
	if (i == 10)
		return ("rrr");
	return (NULL);
}

char	*reverse_op_name(int i)
{
	if (i == 0 || i == 1 || i == 2)
		return (op_name(i));
	if (i == 3)
		return ("pb");
	if (i == 4)
		return ("pa");
	if (i == 5)
		return ("rra");
	if (i == 6)
		return ("rrb");
	if (i == 7)
		return ("rrr");
	if (i == 8)
		return ("ra");
	if (i == 9)
		return ("rb");
	if (i == 10)
		return ("rr");
	return (NULL);
}

char	*sort_stack(t_disc **a, t_disc **b)
{
	char	*instructions;
	int		*try_ops;
	int		i;

	if (!*b && is_sorted(*a))
	{
		instructions = malloc(1);
		if (!instructions)
			return (NULL);
		*instructions = 0;
		return (instructions);
	}
	try_ops = update_ops(*a, *b);
	i = -1;
	while (++i < 11 )
	{
		if (try_ops[i])
		{
			exec_op(a, b, op_name(i));
			ft_printf("Trying %s...\n", op_name(i));
			instructions = sort_stack(a, b);
			if (instructions)
			{
				instructions = ft_strjoin("\n", instructions);
				return (ft_strjoin(op_name(i), instructions));
			}
			exec_op(a, b, reverse_op_name(i));
		}
	}
	return (NULL);
}
