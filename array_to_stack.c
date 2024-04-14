/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_to_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 12:31:28 by yshalash      #+#    #+#                 */
/*   Updated: 2024/04/14 14:50:48 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (stack == NULL || stack->head == NULL)
		return ;
	current = stack->head;
	while (current->next != stack->head)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	stack->head = NULL;
	free(stack);
}

t_node	*create_node(long data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, long data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
	{
		return ;
	}
	if (stack->head == NULL)
	{
		stack->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->prev = stack->head->prev;
		new_node->next = stack->head;
		stack->head->prev->next = new_node;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
}

t_stack	*array_to_stack_desc(long arr[], int size)
{
	t_stack	*stack;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	i = size - 1;
	while (i >= 0)
	{
		push(stack, arr[i]);
		i--;
	}
	return (stack);
}

t_stack	*array_to_stack_asc(long arr[], int size)
{
	t_stack	*stack;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	i = 0;
	while (i < size)
	{
		push(stack, arr[i]);
		i++;
	}
	return (stack);
}
