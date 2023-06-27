/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 18:49:44 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_disc	*a;
	t_disc	*b;
	char	*instructions;
	
	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	b = NULL;
	if (a == NULL)
		return (1);
	instructions = malloc(1);
	if (!instructions)
		return (1);
	*instructions = 0;
//	instructions = sort_stack(&a, &b, instructions);
	display_instructions(instructions);
	display_discs(a, NULL);
	if (a)
		free_disc(a);
	if (instructions)
		free(instructions);
	return (0);
}
