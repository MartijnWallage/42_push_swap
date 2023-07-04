/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/04 18:34:06 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_disc **a, t_disc **b)
{
	int		i;
	int		lowest_rank;
	int		size;

	if (!*b && is_sorted(*a))
		return ;
	if (!*b && discsort_fails(*a) == 0)
	{
		i = get_index(*a, 0);
		move_to_front(a, i);
		return ;
	}
	size = disc_size(*a);
	if (size < 4 && discsort_fails(*a))
	{
		swap(a);
		ft_printf("sa\n");
		sort_stack(a, b);
		return ;
	}
	if (*b && discsort_fails(*a) == 0 && discsort_fails(*b) == 0)
	{
//		display_discs(*a, *b);
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
		sort_stack(a, b);
		return ;
	}
	lowest_rank = get_lowest_rank(*b);
	if (discsort_fails(*a))
	{
		i = first_wrong_pair(*a);
		move_to_front(a, i);
		if (is_sorted_pair(*a, ft_disclast(*a), (*a)->next) && is_sorted_pair(*a, (*a)->next, *a)
			&& is_sorted_pair(*a, *a, next(*a, (*a)->next)))
		{
			swap(a);
			ft_printf("sa\n");
			sort_stack(a, b);
			return ;
		}
		push(a, b);
		if (discsort_fails(*b) == 0)
		{
			ft_printf("pb\n");
			sort_stack(a, b);
			return ;
		}
		else
			push(b, a);
		rotate(b);
		ft_printf("rb\n");
		sort_stack(a, b);
	}
}
