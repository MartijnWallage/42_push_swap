/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/05 18:27:20 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 *	Some things to take care of:
 * 	Now I push the number of the first wrong pair. Better:
 *	Calculate the pushing costs for each number, and push the cheapest one.
 *	Use double rotate.
 *	3 2 1 5 4 is taking too many instructions
 *	100 and 500 are taking too many instructions
 *	Remove traces.
 * 	Remove // comments
 * 	Error handling
 * 	No duplicates are allowed
 *  Remove this.
 */

int main(int argc, char **argv)
{
	t_disc	*a;
	t_disc	**b;
	
	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	if (a == NULL)
		return (1);
	b = malloc(sizeof(t_disc *));
	if (!b)
		return (1);
	*b = NULL;
	sort_stack(&a, b);
	free_disc(a);
	free(b);
	return (0);
}
