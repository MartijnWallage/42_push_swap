/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:25:41 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/14 14:47:00 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	insertion_sort(t_disc **tab, int size)
{
	int		i;
	int		j;
	t_disc	*key;

	i = 0;
	while (++i < size)
	{
		key = tab[i];
		j = i;
		while (--j >= 0 && tab[j]->rank > key->rank)
			tab[j + 1] = tab[j];
		tab[j + 1] = key;
	}
}

void	rank(t_disc *disc)
{
	t_disc	**tab;
	int		size;
	int		i;

	size = disclen(disc);
	tab = malloc(sizeof(t_disc *) * size);
	if (!tab)
		ft_error(ERROR, disc);
	i = -1;
	while (++i < size)
	{
		tab[i] = disc;
		disc = disc->next;
	}
	insertion_sort(tab, size);
	i = -1;
	while (++i < size)
		tab[i]->rank = i;
	free(tab);
}
