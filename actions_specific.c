/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_specific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:42:22 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/20 19:44:01 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_pa(t_program *ps)
{
	t_stack	*new_node;

	new_node = ps->b;
	ps->b = ps->b->next;
	new_node->next = ps->a;
	ps->a = new_node;
	ps->a_first_node = ps->a;
	ps->b_first_node = ps->b;
	ft_putact("p", 'a');
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
	ft_putact("p", 'b');
}