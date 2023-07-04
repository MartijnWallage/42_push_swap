/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/04 16:42:55 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_disc	*a;
	t_disc	**b;
	
	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	if (a == NULL)
		return (1);
	display_discs(a, NULL);
	b = malloc(sizeof(t_disc *));
	if (!b)
		return (1);
	*b = NULL;
	sort_stack(&a, b);
	display_discs(a, *b);
/*	read = 1;
	while (read)
	{
		op = get_next_op();
		if (!op)
			read = 0;
		else
		{
			exec_op(&a, &b, op);
			display_discs(a, b);
		}
		ft_printf("Stack a is %d steps away from being discsort_fails\n", discsort_fails(a, 0));
		ft_printf("Stack b is %d steps away from being discsort_fails\n", discsort_fails(b, 1));
	}*/
//	instructions = sort_stack(&a, &b, instructions);
//	display_instructions(instructions);
//	display_discs(a, NULL);
	free_disc(a);
	free(b);
	return (0);
}
