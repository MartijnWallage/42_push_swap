/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/07 19:21:50 by mwallage         ###   ########.fr       */
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

void	calc_pushcosts(t_disc *a, t_disc *b)
{
	t_disc	*current;
	int		size;
	int		i;
	
	if (!a)
		return ;
	current = a;
	size = max(disc_size(a), disc_size(b));
	i = 0;
	while (current && i <= size / 2)
	{
		current->cost = max(i, find_place(b, current->rank)) + 1;
		i++;
		current = current->next;
	}
	while (current && i < size)
	{
		current->cost = max(disc_size(a) - i, disc_size(b) - find_place(b, current->rank)) + 1;
		i++;
		current = current->next;
	}
}

t_disc	*find_cheapest(t_disc *disc)
{
	t_disc	*current;
	t_disc	*cheapest;
	
	current = disc;
	cheapest = NULL;
	while (current)
	{
		if (current->rank != 0 && (!cheapest || current->cost < cheapest->cost))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	double_move_to_front(t_disc **a, int target_a, t_disc **b, int target_b)
{
	int	distance;
	int	a_revrot;
	int	b_revrot;
	int	reverse;
	int	i;
	
	a_revrot = disc_size(*a) - target_a;
	b_revrot = disc_size(*b) - target_b;
	reverse = max(a_revrot, b_revrot) < max(target_a, target_b);
	distance = min(max(a_revrot, b_revrot), max(target_a, target_b));
	i = 0;
	if (reverse)
	{
		while (i < min(a_revrot, b_revrot))
		{
			double_revrot(a, b);
			i++;
		}
		while (i < a_revrot)
		{
			reverse_rotate(a);
			ft_printf("rrr\n");
			i++;
		}
		while (i < b_revrot)
		{
			reverse_rotate(b);
			ft_printf("rrr\n");
			i++;
		}
	}
	else
	{
		while (i < min(target_a, target_b))
		{
			double_rot(a, b);
			i++;
		}
		while (i < target_a)
		{
			rotate(a);
			ft_printf("ra\n");
			i++;
		}
		while (i < target_b)
		{
			rotate(b);
			ft_printf("rb\n");
			i++;
		}
	}
}

void	sort_stack(t_disc **a, t_disc **b)
{
	t_disc	*cheapest_a;
	int		insert;

	if (!*b && is_sorted(*a))
		return ;
	if (!*b && wrong_pairs(*a) == 0)
		move_to_front(a, get_index(*a, 0));
	else if (disc_size(*a) == 3 && wrong_pairs(*a))
	{
		swap(a);
		ft_printf("sa\n");
		sort_stack(a, b);
	}
	else if (*b && wrong_pairs(*a) == 0 && wrong_pairs(*b) == 0)
	{
		merge_stacks(a, b);
		sort_stack(a, b);
	}
	else if (wrong_pairs(*a))
	{
		calc_pushcosts(*a, *b);
//		display_discs(*a, *b);
		cheapest_a = find_cheapest(*a);
		insert = find_place(*b, cheapest_a->rank);
		double_move_to_front(a, cheapest_a->index, b, insert);
		push(a, b);
		ft_printf("pb\n");
		sort_stack(a, b);
/*		i = first_wrong_pair(*a);
		move_to_front(a, i);
		if (try_swap(a))
		{
			ft_printf("sa\n");
			sort_stack(a, b);
		}
		else if (try_push(a, b))
		{
			ft_printf("pb\n");
			sort_stack(a, b);
		}
		else
		{
			move_to_front(b, find_place(*b, (*a)->rank));
			push(a, b);
			ft_printf("pb\n");
			sort_stack(a, b);
		}*/
	}
}
