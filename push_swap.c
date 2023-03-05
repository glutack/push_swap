/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:17 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/01 18:16:58 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_index(t_program *ps)
{
	if (ps->a->index > ps->a->next->index && ps->a->index > ps->a->next->next->index)
		ps->a = ft_ra(ps);
	//else if (ps->a->next->index > (ps->a->index && ps->a->next->next->index))
	else if (ps->a->index > ps->a->next->index)
		ps->a = ft_swap_a(ps);
}

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

/*If first arg contains all numbers, it splits them into different str, if
numbers already come as different args it deletes the first one (./push_swap)
and allocates memory*/
int	main(int argc, char **argv)
{
	t_program	*ps;

	ps = NULL;
	ps = ft_init_ps(ps);
	if (argc < 2 || (!ft_ps_prep(ps, argc, argv)))
		return (1);
	if (!ft_issorted(ps) && ps->total_index == 2)
		ps->a = ft_swap_a(ps);
	if (!ft_issorted(ps) && ps->total_index == 3)
		ft_check_index(ps);
	while (ps->a != NULL)
	{
		ft_putnbr_fd(ps->a->num, 1);
		ps->a = ps->a->next;
	}
	ft_putstr_fd("tot be\n", 1);
	free(ps);
	return (0);
}