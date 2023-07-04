/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:52:40 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/04 17:41:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_disc **a, t_disc **b)
{
	int		i;
	int		lowest_rank;

	if (!*b && is_sorted(*a))
		return ;
	if (!*b && discsort_fails(*a) == 0)
	{
		ft_printf("Moving 0 to front and done\n");
		i = get_index(*a, 0);
		move_to_front(a, i);
		return ;
	}
	if (*b && discsort_fails(*a) == 0 && discsort_fails(*b) == 0)
	{
		ft_printf("Both are disc sorted.\n");
		display_discs(*a, *b);
		if ((*b)->rank > get_highest_rank(*a))
		{
			ft_printf("bringing 0 to front\n");
			i = get_index(*a, 0);
			move_to_front(a, i);
			push(b, a);
			sort_stack(a, b);
			return ;
		}
		if ((*b)->rank < (*a)->rank && (*b)->rank > ft_disclast(*a)->rank)
		{
			push(b, a);
			sort_stack(a, b);
			return ;
		}
		rotate(a);
		sort_stack(a, b);
		return ;
	}
	lowest_rank = get_lowest_rank(*b);
	if (discsort_fails(*a))
	{
		i = first_wrong_pair(*a);
		ft_printf("%d is the first wrong pair on a\n", i);
		move_to_front(a, i);
		if (is_sorted_pair(*a, ft_disclast(*a), (*a)->next) && is_sorted_pair(*a, (*a)->next, *a)
			&& is_sorted_pair(*a, *a, next(*a, (*a)->next)))
		{
			swap(a);
			sort_stack(a, b);
			return ;
		}
		push(a, b);
		if (discsort_fails(*b) == 0)
		{
			sort_stack(a, b);
			return ;
		}
		else
		{
			ft_printf("OK that didn't work\n");
			push(b, a);
		}
		rotate(b);
		sort_stack(a, b);
	}
}
