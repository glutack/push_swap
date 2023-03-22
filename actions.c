/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:57:02 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/21 13:50:48 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	swap -> swaps the first 2 elements at the top of stack. Does nothing if
	there's only one or no elements.*/
t_stack	*ft_swap(t_stack *stack, char c, t_program *ps)
{
	t_stack	*new_node;

	new_node = stack->next;
	if (stack && stack->next != NULL)
	{
		stack->next = new_node->next;
		new_node->next = stack;
		if (c == 'a')
			ps->a_first_node = new_node;
		else if (c == 'b')
			ps->b_first_node = new_node;
		ft_putact("s", c);
		return (new_node);
	}
	return (stack);
}

/*	rotate -> shifts all elements of the stack up by 1. 1st element becomes the
	last one.*/
t_stack	*ft_r(t_stack *stack, char c, t_program *ps)
{
	t_stack	*first;
	t_stack	*aux;

	aux = stack;
	first = stack->next;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = aux;
	stack->next->next = NULL;
	if (c == 'a')
		ps->a_first_node = first;
	else if (c == 'b')
		ps->b_first_node = first;
	if (c == 'a' || c == 'b')
		ft_putact("r", c);
	return (first);
}

/*	rotate a & rotate b -> rotates both stacks*/
void	ft_rr(t_program *ps)
{
	ps->a = ft_r(ps->a, 'c', ps);
	ps->a_first_node = ps->a;
	ps->b = ft_r(ps->b, 'c', ps);
	ps->b_first_node = ps->b;
	ft_putact("r", 'r');
}

/*	reverse rotate -> shifts all elements of stack b down by 1. Last element
	becomes the 1st one. */
t_stack	*ft_revr(t_stack *stack, char c, t_program *ps)
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
	if (c == 'a')
		ps->a_first_node = first;
	else if (c == 'b')
		ps->b_first_node = first;
	if (c == 'a' || c == 'b')
		ft_putact("rr", c);
	return (first);
}

/*	reverse rotate a & reverse rotate b -> rr both stacks */
void	ft_rrr(t_program *ps)
{
	ps->a = ft_revr(ps->a, 'c', ps);
	ps->a_first_node = ps->a;
	ps->b = ft_revr(ps->b, 'c', ps);
	ps->b_first_node = ps->b;
	ft_putact("rr", 'r');
}