/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:42:22 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/21 12:54:53 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	push a -> puts 1st element in stack b at the top of stack a. Does nothing
	if b is empty.*/
void	ft_pa(t_program *ps)
{
	t_stack	*new_node;

	if (ps->b != NULL)
	{
		new_node = ps->b;
		ps->b = ps->b->next;
		new_node->next = ps->a;
		ps->a = new_node;
		ps->a_first_node = ps->a;
		ps->b_first_node = ps->b;
		ft_putact("p", 'a');
	}
}

/*	push b -> puts 1st element in stack a at the top of stack b. Does nothing
	if a is empty.*/
void	ft_pb(t_program *ps)
{
	t_stack	*new_node;

	if (ps->a != NULL)
	{
		new_node = ps->a;
		ps->a = ps->a->next;
		new_node->next = ps->b;
		ps->b = new_node;
		ps->b_first_node = ps->b;
		ps->a_first_node = ps->a;
		ft_putact("p", 'b');
	}
}
