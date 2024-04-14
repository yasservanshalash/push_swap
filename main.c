/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yshalash <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/14 12:32:13 by yshalash      #+#    #+#                 */
/*   Updated: 2024/04/14 13:32:19 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long	*numbers_array;
	int		size;
	t_stack	*a;
	t_stack	*b;

	numbers_array = return_numbers(argc, argv, &size);
	a = array_to_stack_desc(numbers_array, size);
	b = (t_stack *)malloc(sizeof(t_stack));
	b->head = NULL;
	sort_stack_asc(&a, &b);
	free(numbers_array);
	free_stack(a);
	free(b);
	return (0);
}
