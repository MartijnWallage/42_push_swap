/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:17 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 13:44:42 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	display_stacks(t_list *a, t_list *b)
{
	ft_printf("\na\tb\n");
	ft_printf("|\t|\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d\t", *(int *)(a->content));
			a = a->next;
		}
		else
			ft_printf("\t");
		if (b)
		{
			ft_printf("%d\t", *(int *)(b->content));
			b = b->next;
		}
		ft_printf("\n");
	}
}

void	display_instructions(char *instructions)
{
	if (!instructions)
		printf("");
	else
		printf("%s", instructions);
}