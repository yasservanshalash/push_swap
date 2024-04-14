/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 13:23:30 by yshalash      #+#    #+#                 */
/*   Updated: 2024/04/14 13:31:50 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_logic(int min, int min_index, t_stack *a, t_stack *b)
{
	int	i;

	while (!is_empty(a) && !is_sorted(a))
	{
		min = (a)->head->data;
		min_index = 0;
		i = 0;
		while (i++ < lstsize(a) && !is_sorted(a))
		{
			if ((a)->head->data < min)
			{
				min = (a)->head->data;
				min_index = i;
			}
			ra(a);
		}
		i = 0;
		if (min_index <= lstsize(a) / 2)
			while (i++ < min_index && !is_sorted(a))
				ra(a);
		else
			while (i++ < lstsize(a) - min_index && !is_sorted(a))
				rra(a);
		pb(&a, &b);
	}
}

void	sort_stack_asc(t_stack **a, t_stack **b)
{
	int	min;
	int	min_index;

	min = 0;
	min_index = 0;
	sort_logic(min, min_index, *a, *b);
	while (!is_empty(*b))
		pa(a, b);
}
