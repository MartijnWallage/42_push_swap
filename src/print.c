/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:17 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/21 14:18:40 by mwallage         ###   ########.fr       */
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
	/*
	while (instructions)
	{
		ft_printf("%s", (char *)(instructions->content));
		instructions = instructions->next;
	}*/
}