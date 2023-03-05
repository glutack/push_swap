/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:58:19 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/01 18:16:50 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterr(char *str, t_program *ps, int err)
{
	ft_putstr_fd(str, 2);
	if (err > 0)
	{
		if (err == 1)
			free(ps->argv);
		//free ps->a

	}
	free(ps);
	exit (1);
}