#include "push_swap.h"

int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	long	tmp_value;
	int		tmp_index;

	if (stack == NULL || stack->head == NULL
		|| stack->head->next == stack->head)
	{
		return (-1);
	}
	first = stack->head;
	second = first->next;
	tmp_value = first->data;
	tmp_index = first->index;
	first->data = second->data;
	first->index = second->index;
	second->data = tmp_value;
	second->index = tmp_index;
	return (0);
}

void	sa(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
