#include "push_swap.h"

t_stack	*ft_swap_a(t_program *ps)
{
	t_stack	*new_node;
	new_node = ps->a->next;
	new_node->next = ps->a;
	new_node->next->next = ps->a->next->next;

	return (new_node);
}

t_stack	*ft_ra(t_program *ps)
{
	t_stack	*aux;

	aux = ps->a;
	ps->a_first_node = ps->a->next;
	while (ps->a->next != NULL)
		ps->a = ps->a->next;
	ps->a->next = aux;
	ps->a->next->next = NULL;
	ps->a = ps->a_first_node;
	return (ps->a);
}