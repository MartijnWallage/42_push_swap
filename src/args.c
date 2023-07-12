/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:25:41 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/12 17:43:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

typedef struct s_rank
{
	int	value;
	int index;
}		t_rank;

void	*ft_error(char *message)
{
	int	len;

	len = ft_strlen(message);
	ft_printf(RED);
	write(2, message, len);
	ft_printf(RESET);
	write(2, "\n", 1);
	exit(1);
}

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

int	has_duplicates(t_disc *disc)
{
	t_disc	*current;
	t_disc	*current2;

	current = disc;
	current2 = disc;
	while (current)
	{
		while (current2)
		{
			if (current != current2 && current->rank == current2->rank)
				return (1);
			current2 = current2->next;
		}
		current = current->next;
	}
	return (0);
}

static char	*ignore_whitespace(char *arg)
{
	while (*arg == ' ' || *arg == '\t' || *arg == '\n' || *arg == '\v'
		|| *arg == '\f' || *arg == '\r')
		arg++;
	return (arg);
}

int	is_integer(char *arg)
{
	int		neg;
	int		found_digit;
	long	nbr;

	arg = ignore_whitespace(arg);
	neg = 1;
	if (*arg == '-')
	{
		neg = -1;
		arg++;
	}
	else if (*arg == '+')
		arg++;
	nbr = 0;
	found_digit = 0;
	while (*arg >= '0' && *arg <= '9')
	{
		found_digit = 1;
		nbr = nbr * 10 + *arg - '0';
		if (neg * nbr > INT_MAX || neg * nbr < INT_MIN)
			return (0);
		arg++;
	}
	arg = ignore_whitespace(arg);
	return (!*arg && found_digit);
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
		if (!is_integer(argv[i]))
			ft_error(ERROR);
		nbr = ft_atoi(argv[i]);
		new_node = ft_discnew(nbr);
		if (new_node == NULL)
			return (free_disc(disc));
		ft_discadd_back(&disc, new_node);
	}
	if (has_duplicates(disc))
		ft_error(ERROR);
	set_rank(disc);
	return (disc);
}
