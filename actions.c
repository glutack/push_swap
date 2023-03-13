/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:57:02 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/12 15:30:53 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap_a(t_program *ps)
{
	t_stack	*new_node;

	new_node = ps->a->next;
	ps->a->next = new_node->next;
	new_node->next = ps->a;

	return (new_node);
}

t_stack	*ft_ra(t_program *ps)
{
	t_stack	*aux;

	aux = ps->a;
	ps->a_first_node = ps->a->next;
	while (ps->a->next != NULL)
		ps->a = ps->a->next;
	ps->a->next = aux;
	ps->a->next->next = NULL;
	ps->a = ps->a_first_node;
	return (ps->a);
}