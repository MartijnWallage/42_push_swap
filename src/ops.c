/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:49:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/06/27 19:34:48 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*get_next_op(void)
{
	return (ft_strtrim(get_next_line(stdin->_fileno), " \n"));
}

void	swap(t_disc **a)
{
	t_disc	*new_first;
	t_disc	*new_second;
	t_disc	*temp;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	new_first = (*a)->next;
	new_second = *a;
	temp = new_first->next;
	new_first->next = new_second;
	new_first->previous = new_second->previous;
	new_first->index = new_second->index;
	new_second->previous = new_first;
	new_second->next = temp;
	new_second->index = new_first->index + 1;
	*a = new_first;
}

void	push(t_disc **a, t_disc **b)
{
	t_disc	*new_head;

	if (!a || !b || !*a)
		return ;
	new_head = (*a)->next;
	ft_discadd_front(b, *a);
	*a = new_head;
}

void	rotate(t_disc **a)
{
	t_disc	*head;

	if (!a || !*a || !(*a)->next)
		return ;
	head = (*a)->next;
	ft_disclast(*a)->next = *a;
	(*a)->next = NULL;
	*a = head;
}

void	reverse(t_disc	**a)
{
	t_disc	*head;
	t_disc	*penultimate;
	
	if (!a | !*a || !(*a)->next)
		return ;	
	head = ft_disclast(*a);
	penultimate = *a;
	while (penultimate->next != head)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	head->next = *a;
	*a = head;
}

void	exec_op(t_disc **a, t_disc **b, char *op)
{
	if (op == NULL || !a || !b)
		return ;
	if (!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "ss", 2))
		swap(a);
	if (!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2))
		swap(b);
	if (!ft_strncmp(op, "pa", 2))
		push(b, a);
	if (!ft_strncmp(op, "pb", 2))
		push(a, b);
	if (!ft_strncmp(op, "ra", 2) || !ft_strncmp(op, "rr", 3))
		rotate(a);
	if (!ft_strncmp(op, "rb", 2) || !ft_strncmp(op, "rr", 3))
		rotate(b);
	if (!ft_strncmp(op, "rra", 3) || !ft_strncmp(op, "rrr", 3))
		reverse(a);
	if (!ft_strncmp(op, "rrb", 3) || !ft_strncmp(op, "rrr", 3))
		reverse(b);
}

void	exec_ops(t_disc **a, t_disc **b)
{
	char	*op;

	ft_printf("\n");
	op = get_next_op();
	while (op)
	{
		exec_op(a, b, op);
		ft_printf("\nExec %s\n", op);
		display_discs(*a, *b);
		free(op);
		op = get_next_op();
	}
}
