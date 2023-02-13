/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:17 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/13 18:54:02 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*arg str to int*/
/*Checks if is digit, argument > int or duplicated numbers*/
int	ft_check_arg(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_create_stack()
{
	if (!lst->stack_a)
		write(2, "a", 1);
	else
		while (argv[i])
			lst->stack_a[j++] = argv[i++];
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	lst;

	i = 1;
	j = 0;
	if (argc == 1)
		return (0);
	else
	
		lst->stack_a = ft_split(argv[1], '\n');
	lst->stack_a = malloc(sizeof(long) * (argc - 1));
	ft_create_stack(argv, &lst);
	return (0);
}