/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:43:19 by irmoreno          #+#    #+#             */
/*   Updated: 2023/03/27 09:54:47 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

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
	int				argc;
	int				i;
	int				j;
	unsigned int	total_index;
	struct s_stack	*a_first_node;
	struct s_stack	*b_first_node;
	struct s_stack	*a;
	struct s_stack	*b;
}				t_program;

// INIT
t_program	*ft_init_stacka(t_program *ps);
t_program	*ft_init_ps(t_program *ps);
void		ft_ps_prep(t_program *ps, int argc, char **argv);

// PUSH_SWAP
int			ft_issorted(t_program *ps);
t_stack		*ft_get_pos(t_stack *stack, t_program *ps);
int			ft_get_target_pos(t_program *ps);
void		ft_get_cost(t_program *ps);
void		ft_next_action(t_program *ps);

// ACTIONS
void		ft_pb(t_program *ps);
void		ft_pa(t_program *ps);
t_stack		*ft_swap(t_stack *stack, char c, t_program *ps);
t_stack		*ft_r(t_stack *stack, char c, t_program *ps);
void		ft_rr(t_program *ps);
t_stack		*ft_revr(t_stack *stack, char c, t_program *ps);
void		ft_rrr(t_program *ps);

// UTILS
void		ft_free_stack(t_stack *stack);
void		ft_puterr(char *str, t_program *ps, int err);
void		ft_putact(char *action, char c);
int			ft_uns_cost(int cost);
int			ft_ps_atoi(t_program *ps, const char *str);

#endif
