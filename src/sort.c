/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/21 18:06:15 by robertrinh    ########   odam.nl         */
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
	if (!already_sorted(stack_a))
	{
		if (first > middle && first < last)
			sa(stack_a);
		else if (first > last && first < middle)
			rra(stack_a);
		else if (last > middle && first > last)
			ra(stack_a);
		else if (middle > last && first > middle)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if (first < middle && first < last)
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
}
#include <stdio.h>
// void	sort_4(t_node **stack_a, t_node **stack_b)
// {
// 	int		lowest;

// 	// lowest = find_lowest_index(stack_a);
// 	// // printf("lowest sort4 is: %d\n", lowest);
// 	// if ((*stack_a)->position == lowest)
// 	// 	rra(stack_a);
// 	t_node	*temp;

// 	temp = *stack_a;
// 	lowest = temp->position;
// 	while (temp->next)
// 	{
// 		if (temp->next->position < lowest)
// 			lowest = temp->next->position;
// 		temp = temp->next;
// 	}
// 	if (temp->position == lowest)
// 		rra(stack_a);
// 	else
// 	{
// 		while ((*stack_a)->position != lowest)
// 			ra(stack_a);
// 	}
// 	pb(stack_a, stack_b);
// 	sort_3(stack_a);
// 	pa(stack_b, stack_a);
// }
// #include <stdio.h>
void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	position;
	
	position = get_position(stack_a);
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}
void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	position;

	position = get_position(stack_a);
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (position == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}
// #include <stdio.h>
// void	sort_5(t_node **stack_a, t_node **stack_b)
// {
// 	int	lowest;
// 	int	i;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		lowest = find_lowest_index(*stack_a);
// 		print_stack(*stack_a);
// 		if ((*stack_a)->position != lowest)
// 		{
// 			ra(stack_a);
// 			print_stack(*stack_a);
// 			printf("lowest = %d\n", lowest);
// 		}
// 		pb(stack_a, stack_b);
// 		i++;
// 		lowest = find_lowest_index(*stack_a);
// 		if ((*stack_a)->position != lowest)
// 		{
// 			ra(stack_a);
// 			print_stack(*stack_a);
// 			printf("lowest = %d\n", lowest);
// 		}
// 		pb(stack_a, stack_b);
// 	}
// 	sort_3(stack_a);
// 	pa(stack_b, stack_a);
// 	pa(stack_b, stack_a);
// 	lowest = find_lowest_index(*stack_a);
// 	while ((*stack_a)->position != lowest)
// 		ra(stack_a);
// }

// void	sort_5(t_node **stack_a, t_node **stack_b)
// {
// 	int		lowest;

// 	lowest = find_lowest_index(stack_a);
// 	// printf("lowest sort5 is: %d\n", lowest);
// 	if ((*stack_a)->position == lowest)
// 		rra(stack_a);
// 	else
// 	{
// 		while ((*stack_a)->position != lowest)
// 			ra(stack_a);
// 	}
// 	pb(stack_a, stack_b);
// 	sort_4(stack_a, stack_b);
// 	pa(stack_b, stack_a);
// 	// lowest = find_lowest_index(stack_a);
// 	// while ((*stack_a)->position != lowest)
// 	// 	ra(stack_a);
// }

// void	sort_5(t_node **stack_a, t_node **stack_b)
// {
// 	int	len;
// 	t_node	*temp;
	
// 	len = lst_len(*stack_a);
// 	while (len > 0)
// 	{
// 		temp = *stack_a;
// 		if (temp->position == 0 || temp->position == 1)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 		len--;
// 	}
// 	sort_3(stack_a);
// 	pa(stack_b, stack_a);
// 	pa(stack_b, stack_a);
// 	if ((temp != NULL) && (temp->next != NULL)
// 			&& (temp->position > temp->next->position))
// 			sa(stack_a);
// 	// if ((*stack_a)->position > (*stack_a)->next->position)
// 	// 	sa(stack_a);
// }	

/**
 * @brief sorts the numbers in an ascending order through an algorithm.
 * @param stack_a stack a that is used to sort
 * @param stack_b stack b that is used to push numbers
*/
void	sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	stack_index(*stack_a);
	len = lst_len(*stack_a);
	if (already_sorted(stack_a))
		return ;
	if (len == 2)
		sort_2(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
