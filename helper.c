/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 13:22:20 by yshalash      #+#    #+#                 */
/*   Updated: 2024/04/14 16:22:10 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack == NULL || stack->head == NULL);
}

int	lstsize(t_stack *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	if (is_empty(stack))
	{
		return (0);
	}
	current = stack->head;
	while (1)
	{
		count++;
		current = current->next;
		if (current == stack->head)
		{
			break ;
		}
	}
	return (count);
}

int	is_sorted(t_stack *list)
{
	t_node	*current;
	t_node	*prev;

	if (list == NULL || list->head == NULL || list->head->next == NULL)
	{
		return (1);
	}
	current = list->head;
	prev = current;
	current = current->next;
	while (current != list->head)
	{
		if (prev->data > current->data)
		{
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (1);
}

int is_sorted_desc(t_stack *stack) {
    if (stack->head == NULL || stack->head->next == NULL) {
        return 1; // Empty or single-element stack is considered sorted
    }
    t_node *current = stack->head;
    t_node *start = stack->head; // Store the starting node

    while (1) {
        if (current->data < current->next->data) {
            return 0; // If current element is less than next element, stack is not sorted
        }
        current = current->next;
        if (current == start) {
            break; // Break the loop when we reach the starting node again
        }
    }

    return 1; // If loop completes without returning, stack is sorted in descending order
}


int	find_max_bits(t_stack *stack)
{
	int		max_bits;
	t_node	*current;
	long	max_value;

	max_bits = 0;
	current = stack->head;
	max_value = 0;
	// Find the max value in the stack
	while (current != NULL)
	{
		if (current->data > max_value)
			max_value = current->data;
		current = current->next;
		if (current == stack->head)
			break ; // Assuming circular linked list
	}
	// Calculate max bits needed for the max value
	while (max_value)
	{
		max_value >>= 1;
		max_bits++;
	}
	return (max_bits);
}
