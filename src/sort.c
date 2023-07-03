/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/03 16:33:54 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	int		i;

	if (!*b && is_sorted(*a))
	{
		instructions = malloc(1);
		if (!instructions)
			return (NULL);
		*instructions = 0;
		return (instructions);
	}
	if (!*b && disc_sorted(*a, 'a') == 0)
	{
		i = get_index(*a, 0);
		instructions = move_to_front(a, 'a', i);
		return (instructions);
	}
	if (!disc_sorted(*a, 'a') && !disc_sorted(*b, 'b'))
	{
		if ((*b)->rank < (*a)->rank && (*b)->rank > ft_disclast(*a)->rank)
		{
			exec_op(a, b, "pa");
			instructions = sort_stack(a, b);
			if (instructions)
				return (ft_strjoin("pa\n", instructions));
		}
		else
		{
			exec_op(a, b, "ra");
			instructions = sort_stack(a, b);
			if (instructions)
				return (ft_strjoin("ra\n", instructions));
		}
	}
	i = first_wrong_pair(*a, 'a');
	instructions = move_to_front(a, 'a', i);
	if (is_sorted_pair(*a, 'a', ft_disclast(*a), (*a)->next) && is_sorted_pair(*a, 'a', (*a)->next, *a)
		&& is_sorted_pair(*a, 'a', *a, next(*a, (*a)->next)))
	{
		exec_op(a, b, "sa");
		instructions = ft_strjoin(instructions, sort_stack(a, b));
		if (instructions)
			return (ft_strjoin("sa\n", instructions));
	}
	else if (is_sorted_pair(*b, 'b', previous(*b, *b), *a) && is_sorted_pair(*b, 'b', *a, *b))
	{
		exec_op(a, b, "pb");
		instructions = ft_strjoin(instructions, sort_stack(a, b));
		if (instructions)
			return (ft_strjoin("pb\n", instructions));
	}
	else
	{
		exec_op(a, b, "rb");
		instructions = ft_strjoin(instructions, sort_stack(a, b));
		if (instructions)
			return (ft_strjoin("rb\n", instructions));
	}
	return (NULL);
}
