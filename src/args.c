/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:25:41 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/29 19:05:57 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_rank(t_disc *disc)
{
	disc++;
/*	t_disc	*current;
	int		*ranked;
	int		size;
	int		i;
	int		min;
	
	size = disc_size(disc);
	ranked = malloc(sizeof(int) * size);
	if (ranked == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		ranked[i] = 0;
		i++;
	}
	i = 0;
	while (i < size)
	{
		current = disc;
		while (current)
		{
			if (!ranked[current->index] && current->rank < min)
			{
				ranked[current->index] = rank;
			}
		}
	}*/
}

char	*get_next_op(void)
{
	char	*unparsed_input;
	char	*parsed_input;
	
	unparsed_input = get_next_line(stdin->_fileno);
	if (unparsed_input == NULL)
		return (NULL);
	parsed_input = ft_strtrim(unparsed_input, " \n");
	return (parsed_input);
}

t_disc	*get_args(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_disc	*disc;
	t_disc	*new_node;

	disc = NULL;
	i = 0;
	while (++i < argc)
	{
		nbr = ft_atoi(argv[i]);
		new_node = ft_discnew(nbr);
		if (new_node == NULL)
			return (free_disc(disc));
		ft_discadd_back(&disc, new_node);
	}
	set_rank(disc);
	return (disc);
}
