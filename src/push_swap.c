/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/05 15:28:51 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 *	Some things to take care of:
 *	4 1 3 2 5 is taking too many instructions
 *	100 and 500 are taking too many instructions
 * 	smarter rotating
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
