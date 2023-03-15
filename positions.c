/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:21:50 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/14 18:20:53 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_program *ps)
{
	ps->i = 1;
	while (ps->a != NULL)
	{
		if (ps->a->index == ps->i)
		{
			ps->a = ps->a->next;
			ps->i++;
		}
		else
		{
			ps->a = ps->a_first_node;
			return (0);
		}
	}
	ps->a = ps->a_first_node;
	return (1);
}

void	ft_get_pos(t_program *ps)
{
	ps->i = 0;
	while (ps->a != NULL)
	{
		ps->a->pos = ps->i++;
		ps->a = ps->a->next;
	}
	ps->i = 0;
	ps->a = ps->a_first_node;
	while (ps->b != NULL)
	{
		ps->b->pos = ps->i++;
		ps->b = ps->b->next;
	}
	ps->b = ps->b_first_node;
}

void	ft_get_target_pos(t_program *ps)
{
	ps->i = 1;
	/*while (ps->b != NULL)
	{
		while (ps->i <= ps->total_index && ps->b != NULL)
		{
			if (ps->b->index == ps->total_index)
			{
				while (ps->a->index != 1)
					ps->a = ps->a->next;
				ps->b->target_pos = ps->a->pos;
				ps->b = ps->b->next;
				ps->a = ps->a_first_node;
			}
			else if (ps->a->index == ps->b->index + ps->i)
			{
				ps->b->target_pos = ps->a->pos;
				ps->b = ps->b->next;
				ps->a = ps->a_first_node;
			}
			ps->i++;
		}
		ps->i = 1;
		if (ps->b != NULL)
			ps->b = ps->b->next;
	}*/
	ps->b = ps->b_first_node;
	ps->a = ps->a_first_node;
}
