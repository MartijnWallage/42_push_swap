/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/05 18:03:21 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	merge_stacks(t_disc **a, t_disc **b)
{
	int	i;

	if ((*b)->rank > get_highest_rank(*a))
	{
		i = get_index(*a, 0);
		move_to_front(a, i);
		push(b, a);
		ft_printf("pa\n");
		sort_stack(a, b);
		return ;
	}
	if ((*b)->rank < (*a)->rank && (*b)->rank > ft_disclast(*a)->rank)
	{
		push(b, a);
		ft_printf("pa\n");
		sort_stack(a, b);
		return ;
	}
	rotate(a);
	ft_printf("ra\n");
}

int	find_place(t_disc *disc, int target)
{
	t_disc	*current;
	t_disc	*highest;
	t_disc	*return_node;

	if (!disc)
		return (0);
	highest = disc;
	current = disc;
	return_node = NULL;
	if (disc->stack == 'b')
	{
		while (current)
		{
			if (current->rank > highest->rank)
				highest = current;
			if (target > current->rank && (!return_node || current->rank > return_node->rank))
				return_node = current;
			current = current->next;
		}
		if (!return_node)
			return_node = highest;
	}
	if (disc->stack == 'a')
	{
		while (current)
		{
			if (target < current->rank && (!return_node || current->rank < return_node->rank))
				return_node = current;
			current = current->next;
		}
	}
	return (return_node->index);
}

void	sort_stack(t_disc **a, t_disc **b)
{
	int		i;

	if (!*b && is_sorted(*a))
		return ;
//	display_discs(*a, *b);
//	ft_printf("What to do? Wrong pairs a: %d, Wrong pairs b: %d\n", wrong_pairs(*a), wrong_pairs(*b));
	if (!*b && wrong_pairs(*a) == 0)
		move_to_front(a, get_index(*a, 0));
	else if (*b && wrong_pairs(*a) == 0 && wrong_pairs(*b) == 0)
	{
//		ft_printf("Merging stacks...\n");
//		display_discs(*a, *b);
		merge_stacks(a, b);
		sort_stack(a, b);
	}
	else if (wrong_pairs(*a))
	{
//		ft_printf("A not yet disc sorted...\n");
//		display_discs(*a, *b);
		if (try_swap(a))
		{
			ft_printf("sa\n");
			sort_stack(a, b);
			return ;
		}
		i = first_wrong_pair(*a);
		move_to_front(a, i);
		if (try_push(a, b))
		{
			ft_printf("pb\n");
			sort_stack(a, b);
			return ;
		}
		move_to_front(b, find_place(*b, (*a)->rank));
		push(a, b);
		ft_printf("pb\n");
		sort_stack(a, b);
	}
}
