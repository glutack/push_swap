/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:17 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/27 09:59:56 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checks if the indexes in stack a are already sorted, if they're it returns 1,
else it returns 0 */
int	ft_issorted(t_program *ps)
{
	ps->i = 1;
	while (ps->a->next != NULL)
	{
		if (ps->a->index > ps->a->next->index)
		{
			ps->a = ps->a_first_node;
			return (0);
		}
		ps->a = ps->a->next;
	}
	ps->a = ps->a_first_node;
	return (1);
}

/*	sorts up to 3 elements in stack a depending on its indexes */
void	ft_sort_small(t_program *ps)
{
	while (!ft_issorted(ps))
	{
		if (ps->a->index > ps->a->next->index
			&& ps->a->index > ps->a->next->next->index)
			ps->a = ft_r(ps->a, 'a', ps);
		else if (ps->a->next->index > ps->a->index
			&& ps->a->next->index > ps->a->next->next->index)
			ps->a = ft_revr(ps->a, 'a', ps);
		else if (ps->a->index > ps->a->next->index)
			ps->a = ft_swap(ps->a, 'a', ps);
	}
}

/*	sorts +3 elements: sends all elements to pb except 3 (and sorts them), 
	gets each element position in both stacks, next it gets all target positions
	for elements in stack b, then it gets the number of moves (cost) each
	element will need to get to the target position for ft_next_action to decide
	which actions will be done depending on the minimum cost */
void	ft_sort_big(t_program *ps)
{
	while (ps->a->next->next->next != NULL)
		ft_pb(ps);
	ft_sort_small(ps);
	while (ps->b != NULL)
	{
		ps->a = ft_get_pos(ps->a, ps);
		ps->b = ft_get_pos(ps->b, ps);
		while (ps->b != NULL)
		{
			ps->b->target_pos = ft_get_target_pos(ps);
			ps->b = ps->b->next;
		}
		ps->b = ps->b_first_node;
		ft_get_cost(ps);
		ft_next_action(ps);
	}
	while (ps->a->index != 1)
		ps->a = ft_revr(ps->a, 'a', ps);
}

/*	allocates memory for t_program ps, structure where we're going to keep
	all of our lists and auxs.
	- If program isn't sent any elements, or preparation of the program goes
	wrong, it returns control to the user.
	- If stacka isn't sorted and program gets <= 3 elements, sort_small
	- If stacka isn't sorted and program gets >= 4 elements, sort_big */
int	main(int argc, char **argv)
{
	t_program	*ps;

	ps = NULL;
	ps = ft_init_ps(ps);
	if (argc == 1)
	{
		free(ps);
		return (1);
	}
	ft_ps_prep(ps, argc, argv);
	if (!ft_issorted(ps) && ps->total_index == 2)
		ft_swap(ps->a, 'a', ps);
	else if (!ft_issorted(ps) && ps->total_index <= 3)
		ft_sort_small(ps);
	else if (!ft_issorted(ps) && ps->total_index >= 4)
		ft_sort_big(ps);
	ps->a = ps->a_first_node;
	ft_free_stack(ps->a);
	free(ps);
	return (0);
}
