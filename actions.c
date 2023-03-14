/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:57:02 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/14 12:57:45 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *action, char c)
{
	ft_putstr_fd(action, 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

t_stack	*ft_swap(t_stack *stack, char c)
{
	t_stack	*new_node;

	new_node = stack->next;
	stack->next = new_node->next;
	new_node->next = stack;
	ft_putstr("s", c);
	return (new_node);
}

void	*ft_pb(t_program *ps)
{
	t_stack	*new_node;

	new_node = ps->a;
	ps->a = ps->a->next;
	new_node->next = ps->b;
	ps->b = new_node;
	ps->b_first_node = ps->b;
	ps->a_first_node = ps->a;
	ft_putstr("p", 'b');
}

t_stack	*ft_r(t_stack *stack, char c)
{
	t_stack	*first;
	t_stack	*aux;

	aux = stack;
	first = stack->next;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = aux;
	stack->next->next = NULL;
	ft_putstr("r", c);
	return (first);
}

t_stack	*ft_rra(t_stack *stack, char c)
{
	t_stack	*first;
	t_stack	*aux;

	first = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	aux = stack;
	stack = stack->next;
	stack->next = first;
	first = stack;
	aux->next = NULL;
	ft_putstr("rr", c);
	return (first);
}

