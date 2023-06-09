/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:56:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/14 14:45:07 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_disc	*a;
	t_disc	**b;

	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	b = malloc(sizeof(t_disc *));
	if (!b)
		ft_error(ERROR, a);
	*b = NULL;
	sort_stack(&a, b);
	free_disc(a);
	free(b);
	return (0);
}
