/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:53:32 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/27 09:58:22 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_find_next_max(t_program *ps, t_stack *max)
{
	while (ps->a != NULL && (max->num > ps->a->num || ps->a->index != 0))
			ps->a = ps->a->next;
	if (ps->a == NULL)
	{
		max->index = ps->i;
		ps->i--;
	}
	else
		max = ps->a;
	if (max->index == 0)
		ps->a = max->next;
	else
	{
		max = ps->a_first_node;
		while (max != NULL && max->index != 0)
			max = max->next;
		if (max != NULL)
			ps->a = max->next;
	}
	return (max);
}

static t_program	*ft_put_index(t_program *ps)
{
	t_stack	*max;

	max = ps->a;
	max->num = ps->a->num;
	ps->a = ps->a->next;
	while (ps->i > 0)
		max = ft_find_next_max(ps, max);
	return (ps);
}

static t_program	*ft_check_double(t_program *ps)
{
	t_stack	*loop;

	loop = ps->a;
	while (loop != NULL)
	{
		ps->j = loop->num;
		ps->a = loop->next;
		while (ps->a != NULL)
		{
			if (ps->j == ps->a->num)
				ft_puterr("Error\nDuplicated number in arg", ps, 2);
			ps->a = ps->a->next;
		}
		loop = loop->next;
	}
	ps->a = ps->a_first_node;
	return (ps);
}

static t_program	*ft_fill_stacka(t_program *ps)
{
	ps->i = 0;
	while (ps->argv[ps->i] != NULL)
	{
		ps->a->num = ft_ps_atoi(ps, ps->argv[ps->i]);
		ps->a->index = 0;
		if (ps->argv[ps->i + 1] != NULL)
		{
			ps->a->next = (t_stack *)malloc(sizeof(t_stack));
			if (!ps->a)
				ft_puterr("Error\nFailed memory allocation", ps, 2);
			ps->a = ps->a->next;
		}
		ps->i++;
	}
	ps->total_index = ps->i;
	ps->a->next = NULL;
	ps->a = ps->a_first_node;
	return (ps);
}

/* 	initializes stacka
	- turns every element (char) to int and saves them in stacka
	- checks doubles
	- assigns an index to all elements */
t_program	*ft_init_stacka(t_program *ps)
{
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	if (!ps->a)
		ft_puterr("Error\nFailed memory allocation", ps, 2);
	ps->a_first_node = ps->a;
	ps = ft_fill_stacka(ps);
	ps = ft_check_double(ps);
	ps = ft_put_index(ps);
	ps->a = ps->a_first_node;
	ps->b = NULL;
	return (ps);
}
