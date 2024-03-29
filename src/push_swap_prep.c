/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:44:44 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/27 09:44:37 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if arg != int
static int	ft_check_int(t_program *ps, char **argv)
{
	ps->i = 1;
	ps->j = 0;
	while (argv[ps->i])
	{
		while (argv[ps->i][ps->j] != '\0')
		{
			if (argv[ps->i][ps->j] == ' ' || ft_isdigit(argv[ps->i][ps->j])
				|| ((argv[ps->i][ps->j] == '-' || argv[ps->i][ps->j] == '+')
					&& ft_isdigit(argv[ps->i][ps->j + 1])
					&& (argv[ps->i][ps->j - 1] == ' ' || ps->j == 0)))
				ps->j++;
			else
				return (0);
		}
		ps->i++;
		ps->j = 0;
	}
	return (1);
}

// allocates memory for struct and ps->argv
t_program	*ft_init_ps(t_program *ps)
{
	ps = (t_program *)malloc(sizeof(t_program));
	if (!ps)
	{
		free(ps);
		ft_putstr_fd("Error\nFailed memory allocation", 2);
		exit (1);
	}
	return (ps);
}

/* prepares program:
- checks if all arg are numbers
- saves all elements in an array
- if all elements come in a single arg it splits them
- initializes stack a */
void	ft_ps_prep(t_program *ps, int argc, char **argv)
{
	ps->argc = argc;
	if (!(ft_check_int(ps, argv)))
		ft_puterr("Error\nIllegal argument", ps, 0);
	if (argc == 2)
		ps->argv = ft_split(argv[1], ' ');
	else
	{
		ps->argv = (char **)malloc(argc * sizeof(char *));
		if (!ps->argv)
			ft_puterr("Error\nFailed memory allocation", ps, 0);
		ps->i = 1;
		ps->j = 0;
		while (argv[ps->i])
			ps->argv[ps->j++] = argv[ps->i++];
		ps->argv[ps->j] = NULL;
	}
	ft_init_stacka(ps);
	if (argc == 2)
		ft_free_split(ps->argv);
	else
		free(ps->argv);
}
