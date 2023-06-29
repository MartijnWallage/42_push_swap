/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/29 18:50:43 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_disc	*a;
	t_disc	*b;
	int		read;
//	char	*instructions;
	char	*op;
	
	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	if (a == NULL)
		return (1);
	b = NULL;
//	instructions = malloc(1);
//	if (!instructions)
//		return (1);
//	*instructions = 0;
	display_discs(a, b);
	read = 1;
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
	}
//	instructions = sort_stack(&a, &b, instructions);
//	display_instructions(instructions);
//	display_discs(a, NULL);
	if (a)
		free_disc(a);
	if (b)
		free_disc(b);
//	if (instructions)
//		free(instructions);
	return (0);
}
