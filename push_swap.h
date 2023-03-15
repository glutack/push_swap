/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:43:19 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/14 18:21:29 by irmoreno         ###   ########.fr       */
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
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

typedef struct s_program {
	char			**argv;
	unsigned int	i;
	unsigned int	j;
	unsigned int	total_index;
	struct s_stack	*aux_pos;
	struct s_stack	*a_first_node;
	struct s_stack	*b_first_node;
	struct s_stack	*a;
	struct s_stack	*b;
}				t_program;

// PREP
t_program	*ft_init_ps(t_program *ps);
int			ft_ps_prep(t_program *ps, int argc, char **argv);
int			ft_issorted(t_program *ps);
void		ft_get_pos(t_program *ps);
void		ft_get_target_pos(t_program *ps);

// INIT STACK
t_program	*ft_init_stacka(t_program *ps);

// ACTIONS
t_stack		*ft_swap(t_stack *stack, char c);
void		*ft_pb(t_program *ps);
t_stack		*ft_r(t_stack *stack, char c);
t_stack		*ft_rra(t_stack *stack, char c);

// ERROR
void		ft_puterr(char *str, t_program *ps, int err);


#endif