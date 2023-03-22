/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:17 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/22 15:45:34 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* */
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
	if (argc <= 1 || (!ft_ps_prep(ps, argc, argv)))
		return (1);
	else if (!ft_issorted(ps) && ps->total_index <= 3)
		ft_sort_small(ps);
	else if (!ft_issorted(ps) && ps->total_index >= 4)
		ft_sort_big(ps);
	ft_putnbr_fd(ps->a_first_node->num, 1);
	ps->a = ps->a_first_node;
	while (ps->a != NULL)
	{
		ft_putnbr_fd(ps->a->num, 1);
		ps->a = ps->a->next;
	}
	ft_putstr_fd("tot be\n", 1);
	free(ps);
	return (0);
}