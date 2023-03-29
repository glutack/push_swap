/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:58:19 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/27 09:55:47 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*aux;

	if (!stack)
		return ;
	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}

void	ft_puterr(char *str, t_program *ps, int err)
{
	if (ps->argc == 2 && err == 1)
		ft_free_split(ps->argv);
	if (err >= 1)
		free(ps->argv);
	if (err > 1 && ps->a)
	{
		ps->a = ps->a_first_node;
		ft_free_stack(ps->a);
	}
	if (err > 1 && ps->b)
	{
		ps->b = ps->b_first_node;
		ft_free_stack(ps->b);
	}
	free(ps);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 1);
	exit (1);
}

void	ft_putact(char *action, char c)
{
	ft_putstr_fd(action, 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

int	ft_uns_cost(int cost)
{
	if (cost < 0)
		return (cost * -1);
	return (cost);
}

int	ft_ps_atoi(t_program *ps, const char *str)
{
	int		sig;
	long	res;

	sig = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if ((res * sig) < -2147483648 || (sig == 1 && res > 2147483647))
		ft_puterr("Error\nNumber > || < than int in arg", ps, 2);
	return ((int)res * sig);
}
