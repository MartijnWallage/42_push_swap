/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:25:41 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/04 16:09:35 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

typedef struct s_rank
{
	int	value;
	int index;
}		t_rank;

void	set_rank(t_disc *disc)
{
	t_rank	*ranks;
	t_disc	*current;
	int		*ranked;
	int		size;
	int		i;
	
	size = disc_size(disc);
	ranks = malloc(sizeof(t_rank) * size);
	if (ranks == NULL)
		return ;
	ranked = malloc(sizeof(int) * size);
	if (ranked == NULL)
	{
		free(ranks);
		return ;
	}
	i = -1;
	while (++i < size)
		ranked[i] = 0;
	i = -1;
	while (++i < size)
	{
		current = disc;
		while (current && ranked[current->index])
			current = current->next;
		ranks[i].value = current->rank;
		ranks[i].index = current->index;
		ranked[current->index] = 1;
		current = disc;
		while (current)
		{
			if (!ranked[current->index] && current->rank < ranks[i].value)
			{
				ranked[ranks[i].index] = 0;
				ranks[i].value = current->rank;
				ranks[i].index = current->index;
				ranked[current->index] = 1;
			}
			current = current->next;
		}
	}
	current = disc;
	while (current)
	{
		i = 0;
		while (ranks[i].index != current->index)
			i++;
		current->rank = i;
		current = current->next;
	}
	free(ranked);
	free(ranks);
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
