/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:51:03 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/22 17:04:52 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

/*	from the costs:
	- if both negative it reverse rotates both stacks
	- if both positive, it rotates both stacks
	- else it rotates stack a and b  
	then pushes the element now in top stack b to top stack a */
static void	ft_do_r_revr(t_program *ps, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		ps->a = ft_r(ps->a, 'a', ps);
		cost_a--;
	}
	while (cost_a < 0)
	{
		ps->a = ft_revr(ps->a, 'a', ps);
		cost_a++;
	}
	while (cost_b > 0)
	{
		ps->b = ft_r(ps->b, 'b', ps);
		cost_b--;
	}
	while (cost_b < 0)
	{
		ps->b = ft_revr(ps->b, 'b', ps);
		cost_b++;
	}
	ft_pa(ps);
}

static void	ft_do_rrr_rr(t_program *ps, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		ft_rrr(ps);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		ft_rr(ps);
		cost_a--;
		cost_b--;
	}
	ft_do_r_revr(ps, cost_a, cost_b);
}

/*	finds the element with the lowest cost in stack a
	ps->i = cost a
	ps->j = cost b */
void	ft_next_action(t_program *ps)
{
	int	low_cost;

	low_cost = INT_MAX;
	while (ps->b != NULL)
	{
		if (ft_uns_cost(ps->b->cost_a) + ft_uns_cost(ps->b->cost_b)
			< ft_uns_cost(low_cost))
		{
			low_cost = ft_uns_cost(ps->b->cost_b) + ft_uns_cost(ps->b->cost_a);
			ps->i = ps->b->cost_a;
			ps->j = ps->b->cost_b;
		}
		ps->b = ps->b->next;
	}
	ps->b = ps->b_first_node;
	ft_do_rrr_rr(ps, ps->i, ps->j);
}
