/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:57:02 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/20 21:26:53 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap(t_stack *stack, char c, t_program *ps)
{
	t_stack	*new_node;

	new_node = stack->next;
	stack->next = new_node->next;
	new_node->next = stack;
	if (c == 'a')
		ps->a_first_node = ps->a;
	else if (c == 'b')
		ps->b_first_node = ps->b;
	ft_putact("s", c);
	return (new_node);
}

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
		ps->a_first_node = ps->a;
	else if (c == 'b')
		ps->b_first_node = ps->b;
	if (c == 'a' || c == 'b')
		ft_putact("r", c);
	return (first);
}

/*	rotate a & rotate b*/
void	*ft_rr(t_program *ps)
{
	ps->a = ft_r(ps->a, 'c', ps);
	ps->a_first_node = ps->a;
	ps->b = ft_r(ps->b, 'c', ps);
	ps->b_first_node = ps->b;
	ft_putact("r", 'r');
}

/*	reverse rotate a single stack */
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
		ps->a_first_node = ps->a;
	else if (c == 'b')
		ps->b_first_node = ps->b;
	if (c == 'a' || c == 'b')
		ft_putact("rr", c);
	return (first);
}

/*	reverse rotate a & reverse rotate b */
void	*ft_rrr(t_program *ps)
{
	ps->a = ft_revr(ps->a, 'c', ps);
	ps->a_first_node = ps->a;
	ps->b = ft_revr(ps->b, 'c', ps);
	ps->b_first_node = ps->b;
	ft_putact("rr", 'r');
}