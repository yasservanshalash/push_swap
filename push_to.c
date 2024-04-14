/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_to.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 12:32:29 by yshalash      #+#    #+#                 */
/*   Updated: 2024/04/14 13:41:26 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_from_source(t_stack **src)
{
	t_node	*node;

	node = (*src)->head;
	if (!node)
		return ;
	if (node->next == node)
		(*src)->head = NULL;
	else
	{
		(*src)->head = node->next;
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	node->next = NULL;
	node->prev = NULL;
}

void	add_to_top_of_dest(t_stack **dest, t_node *node)
{
	if (!(*dest) || !(*dest)->head)
	{
		(*dest)->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = (*dest)->head;
		node->prev = (*dest)->head->prev;
		(*dest)->head->prev->next = node;
		(*dest)->head->prev = node;
		(*dest)->head = node;
	}
}

void	push_to(t_stack **dest, t_stack **src)
{
	t_node	*node;

	if (!src || !(*src)->head)
		return ;
	node = (*src)->head;
	remove_from_source(src);
	add_to_top_of_dest(dest, node);
}

void	pa(t_stack **a, t_stack **b)
{
	push_to(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_to(b, a);
	write(1, "pb\n", 3);
}
