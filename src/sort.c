/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/16 23:14:32 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->position > (*stack_a)->next->position)
		sa(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	first;
	int	middle;
	int	last;
	first = (*stack_a)->position;
	middle = (*stack_a)->next->position;
	last = lst_last(*stack_a)->position;
	if (first > middle && first < last)
		sa(stack_a);
	else if (first > last && first < middle) //2 3 1
		rra(stack_a);
	else if (last > middle && first > last) //3 1 2
		ra(stack_a);
	else if (middle > last && first > middle) //3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first < middle && first < last) //1 3 2
	{
		rra(stack_a);
		sa(stack_a);
	}
}
void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	lowest;
	t_node	*temp;

	temp = *stack_a;
	lowest = temp->position;
	while (temp->next)
	{
		if (temp->next->position < lowest)
			lowest = temp->next->position;
		temp = temp->next;
	}
	if (temp->position == lowest)
		rra(stack_a);
	else
	{
		while ((*stack_a)->position != lowest)
			ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	}
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	lowest;

	lowest = find_lowest_index(stack_a);
	if ((*stack_a)->position == lowest)
		rra(stack_a);
	else
	{
		while ((*stack_a)->position != lowest)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	stack_index(&(*stack_a));
	len = lst_len(*stack_a);
	if (!already_sorted(stack_a) && len == 2)
		sort_2(stack_a);
	else if (!already_sorted(stack_a) && len == 3)
		sort_3(stack_a);
	else if (!already_sorted(stack_a) && len == 4)
		sort_4(stack_a, stack_b);
	else if (!already_sorted(stack_a) && len == 5)
		sort_5(stack_a, stack_b);
	else if (!already_sorted(stack_a))
		radix_sort(stack_a, stack_b);
	// else
	// {
	// 	free_node(stack_a);
	// 	free_node(stack_b);
	// }
}
