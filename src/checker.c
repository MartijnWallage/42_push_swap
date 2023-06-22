/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/19 16:00:17 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (1);
	a = get_args(argc, argv);
	if (a == NULL)
		return (1);
	b = NULL;
	ft_printf("\nInit a and b\n");
	display_stacks(a, b);
	exec_instructions(&a, &b);
	if (is_sorted(a, b))
		ft_printf(GRN "OK" RESET);
	else
		ft_printf(RED "KO" RESET);
	free_stack(a);
	return (0);
}
