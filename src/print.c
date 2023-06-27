/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:17 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 19:18:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_discs(t_disc *a, t_disc *b)
{
	ft_printf("\na\t\tb\n");
	ft_printf("|\t\t|\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("a[%d]=%d\t\t", a->index, a->rank);
			a = a->next;
			if (a && a->index == 0)
				break ;
		}
		else
			ft_printf("\t\t");
		if (b)
		{
			ft_printf("b[%d]=%d\t", b->index, b->rank);
			b = b->next;
			if (b && b->index == 0)
				break ;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	display_instructions(char *instructions)
{
	if (!instructions)
		printf("");
	else
		printf("%s", instructions);
}