/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:25:41 by mwallage          #+#    #+#             */
/*   Updated: 2023/07/14 15:13:35 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(char *message, t_disc *disc)
{
	int	len;

	free_disc(disc);
	len = ft_strlen(message);
	write(STDERR_FILENO, message, len);
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

static void	check_duplicates(t_disc *disc)
{
	t_disc	*current;
	t_disc	*current2;

	current = disc;
	while (current)
	{
		current2 = current->next;
		while (current2)
		{
			if (current->rank == current2->rank)
				ft_error(ERROR, disc);
			current2 = current2->next;
		}
		current = current->next;
	}
}

static char	*ignore_whitespace(char *arg)
{
	while (*arg == ' ' || *arg == '\t' || *arg == '\n' || *arg == '\v'
		|| *arg == '\f' || *arg == '\r')
		arg++;
	return (arg);
}

static int	is_integer(char *arg)
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
			ft_error(ERROR, disc);
		nbr = ft_atoi(argv[i]);
		new_node = discnew(nbr);
		if (new_node == NULL)
			ft_error(ERROR, disc);
		discadd_back(&disc, new_node);
	}
	check_duplicates(disc);
	rank(disc);
	return (disc);
}
