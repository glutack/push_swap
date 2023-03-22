/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:58:19 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/22 15:30:48 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterr(char *str, t_program *ps, int err)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 1);
	if (err > 0)
	{
		if (err == 1)
			free(ps->argv);
		//free ps->a
	}
	free(ps);
	exit (1);
}

void	ft_putact(char *action, char c)
{
	ft_putstr_fd(action, 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

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

int	ft_uns_cost(int cost)
{
	if (cost < 0)
		return (cost * -1);
	return (cost);
}