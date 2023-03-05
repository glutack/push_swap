/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:43:19 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/03 12:01:13 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack {
	int				num;
	int				index;
	int				pos;
	int				target_post;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

typedef struct s_program {
	char			**argv;
	int				i;
	int				j;
	int				total_index;
	struct s_stack	*aux;
	struct s_stack	*a_first_node;
	struct s_stack	*a;
	struct s_stack	*b;
}				t_program;

// PREP
t_program	*ft_init_ps(t_program *ps);
int			ft_ps_prep(t_program *ps, int argc, char **argv);

// INIT STACK
t_program	*ft_init_stacka(t_program *ps);

// ACTIONS
t_stack		*ft_swap_a(t_program *ps);
t_stack		*ft_ra(t_program *ps);

// ERROR
void		ft_puterr(char *str, t_program *ps, int err);


#endif