/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:21:50 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/22 16:38:00 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* assigns its position to every element in the stack */
t_stack	*ft_get_pos(t_stack *stack, t_program *ps)
{
	t_stack	*first;

	first = stack;
	ps->i = 0;
	while (stack != NULL)
	{
		stack->pos = ps->i++;
		stack = stack->next;
	}
	stack = first;
	return (stack);
}

/* finds closest superior index in stacka for every element in stackb and
assings its position as target position for the element in stackb, if there
isn't any it finds the smallest index in stack a and assigns its position as
target position 
ps->i = target index
ps->j = target position */
int	ft_get_target_pos(t_program *ps)
{
	ps->i = INT_MAX;
	ps->j = 0;
	while (ps->a != NULL)
	{
		if (ps->a->index > ps->b->index && ps->a->index < ps->i)
		{
			ps->i = ps->a->index;
			ps->j = ps->a->pos;
		}
		ps->a = ps->a->next;
	}
	ps->a = ps->a_first_node;
	if (ps->i != INT_MAX)
		return (ps->j);
	while (ps->a != NULL)
	{
		if (ps->a->index < ps->i)
		{
			ps->i = ps->a->index;
			ps->j = ps->a->pos;
		}
		ps->a = ps->a->next;
	}
	ps->a = ps->a_first_node;
	return (ps->j);
}

/* 	calculates the cost of moving elements in stack b to the target position in
	stack a. If element is in bottom half, cost will be negative, if is in top
	half it will be positive.
	cost_b = cost of getting the element to stack b top position
	cost_a = cost of getting the element to its target position in stack a
	ps->j = size of stack a
	ps->i = size of stack b*/
void	ft_get_cost(t_program *ps)
{
	ft_get_pos(ps->a, ps);
	ps->j = ps->i;
	ft_get_pos(ps->b, ps);

	while (ps->b != NULL)
	{
		ps->b->cost_b = ps->b->pos;
		if (ps->b->cost_b > ps->i / 2)
			ps->b->cost_b = (ps->i - ps->b->pos) * -1;
		ps->b->cost_a = ps->b->target_pos;
		if (ps->b->target_pos > ps->j / 2)
			ps->b->cost_a = (ps->j - ps->b->target_pos) * -1;
		ps->b = ps->b->next;
	}
	ps->b = ps->b_first_node;
}

/*	from the costs:
	- if both negative it reverse rotates both stacks
	- if both positive, it rotates both stacks
	- else it rotates stack a and b  
	then pushes the element now in top stack b to top stack a
*/
void	ft_do_action(t_program *ps, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			ft_rrr(ps);
			cost_a++;
			cost_b++;
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			ft_rr(ps);
			cost_a--;
			cost_b--;
		}
	}
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ps->a = ft_r(ps->a, 'a', ps);
			cost_a--;
		}
		else if (cost_a < 0)
		{
			ps->a = ft_revr(ps->a, 'a', ps);
			cost_a++;
		}
	}
	while (cost_b)
	{
		if (cost_b > 0)
		{
			ps->b = ft_r(ps->b, 'b', ps);
			cost_b--;
		}
		else if (cost_b < 0)
		{
			ps->b = ft_revr(ps->b, 'b', ps);
			cost_b++;
		}
	}
	ft_pa(ps);
}

/*	finds the element with the lowest cost in stack a
	ps->i = cost a
	ps->j = cost b*/
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
	ft_do_action(ps, ps->i, ps->j);
}