/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 15:18:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


/*
	Scoring:

	Sorted: 		0
	Disc-sorted:	# of rotations needed to get it sorted (use rank)
	b not disc-sorted is worse than a not disc-sorted
*/


int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
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
	instructions = sort_stack(&a, &b, instructions);
	display_instructions(instructions);
	display_stacks(a, NULL);
	if (a)
		free_stack(a);
	if (instructions)
		free(instructions);
	return (0);
}
