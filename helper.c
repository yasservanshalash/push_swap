/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshalash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:20 by yshalash          #+#    #+#             */
/*   Updated: 2024/04/14 13:22:30 by yshalash         ###   ########.fr       */
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
