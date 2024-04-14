/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 13:23:30 by yshalash      #+#    #+#                 */
/*   Updated: 2024/04/14 16:23:13 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_asc(t_stack **a, t_stack **b)
{
	int	min;
	int	size;
	int	min_index;
	int	i;

	while (!is_empty(*a) && !is_sorted(*a))
	{
		// Find the smallest element in stack a
		min = (*a)->head->data;
		size = lstsize(*a);
		min_index = 0;
		i = 0;
		while (i < size && !is_sorted(*a))
		{
			if ((*a)->head->data < min)
			{
				min = (*a)->head->data;
				min_index = i;
			}
			ra(*a);
			i++;
		}
		// Move the smallest element to the top of stack a
		i = 0;
		if (min_index <= size / 2)
		{
			while (i < min_index && !is_sorted(*a))
			{
				ra(*a);
				i++;
			}
		}
		else
		{
			while (i < size - min_index && !is_sorted(*a))
			{
				rra(*a);
				i++;
			}
		}
		// Push the smallest element to stack b
		pb(a, b);
	}
	// Move all elements back to stack a
	while (!is_empty(*b))
	{
		pa(a, b);
	}
}

// for shorter version

// void sort_stack_asc(t_stack **a, t_stack **b) {
//     while (!is_empty(*a) && !is_sorted(*a)) {
//         int min = (*a)->head->data;
//         int size = lstsize(*a);
//         int min_index = 0;
//         int i = 0;

//         // Find the smallest element in stack a
//         for (t_node *current = (*a)->head; current != NULL; current = current->next) {
//             if (current->data < min) {
//                 min = current->data;
//                 min_index = i;
//             }
//             i++;
//         }

//         // Move the smallest element to the top of stack a
//         if (min_index > size / 2) {
//             min_index = size - min_index;
//             while (min_index--) {
//                 rra(*a);
//             }
//         } else {
//             while (min_index--) {
//                 ra(*a);
//             }
//         }

//         // Push the smallest element to stack b
//         pb(a, b);
//     }

//     // Move all elements back to stack a
//     while (!is_empty(*b)) {
//         pa(a, b);
//     }
// }


// void sort_stack_desc(t_stack** a, t_stack** b) {
//     int max_bits = find_max_bits(*a);
//     for (int bit = 0; bit < max_bits && !is_sorted(*a); bit++) {
//         int size = lstsize(*a);
//         for (int i = 0; i < size && !is_sorted(*a); i++) {
//             int mask = 1 << bit; // Calculate mask for the current bit
//             if (((*a)->head->data & mask) == 0) {
//                 // If the bit is not set, perform action A (rotate) instead of B (push to B)
//                 ra(*a);
//             } else {
//                 // If the bit is set, perform action B (push to B) instead of A (rotate)
//                 pb(a, b);
//             }
//         }

//         // Move elements back from B to A, ensuring those with bit 0 are now at the bottom
//         while (!is_empty(*b)) {
//             pa(a, b);
//         }
//     }
//     // After the final iteration, stack A will be sorted in ascending order.
// }

void	sort_stack(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = find_max_bits(*a);
	bit = 0;
	while (bit < max_bits && !is_sorted(*a))
	{
		size = lstsize(*a);
		i = 0;
		while (i < size && !is_sorted(*a))
		{
			if (((*a)->head->data >> bit) & 1)
				// If the bit is set, perform action A (rotate) instead of B (push to B)
				ra(*a);
			else
				// If the bit is not set, perform action B (push to B) instead of A (rotate)
				pb(a, b);
			i++;
		}
		// Move elements back from B to A, ensuring those with bit 1 are now at the bottom
		while (!is_empty(*b))
			pa(a, b);
		bit++;
	}
	// After the final iteration, stack A will be sorted in descending order.
}
