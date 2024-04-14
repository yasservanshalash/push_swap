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

void	sort_stack_asc(t_stack **a, t_stack **b)
{
	int	min;
	int	size;
	int	min_index;
    int i;

	while (!is_empty(*a) && !is_sorted(*a))
	{
		min = (*a)->head->data;
		size = lstsize(*a);
		min_index = 0;
        i = 0;

        while(i < size && !is_sorted(*a))
        {
			if ((*a)->head->data < min)
			{
				min = (*a)->head->data;
				min_index = i;
			}
			ra(*a);
            i++;
        }
        i = 0;

		if (min_index <= size / 2)
		{
            while(i < min_index && !is_sorted(*a))
            {
                ra(*a);
                i++;
            }
		}
		else
		{
			while(i < size - min_index && !is_sorted(*a))
			{
				rra(*a);
                i++;
			}
		}
		pb(a, b);
	}
	while (!is_empty(*b))
	{
		pa(a, b);
	}
}

int	is_empty(t_stack *stack)
{
	return (stack == NULL || stack->head == NULL);
}

int lstsize(t_stack *stack)
{
    int count = 0;
    t_node *current;

    if (is_empty(stack))
    {
        return 0;
    }

    current = stack->head;
    while (1)
    {
        count++;
        current = current->next;
        if (current == stack->head)
        {
            break;
        }
    }
    return count;
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
