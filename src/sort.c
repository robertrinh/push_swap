/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/15 00:08:55 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards
#include <limits.h>

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
	printf("f m l is: %d %d %d\n", first, middle, last);
	print_stack(*stack_a);
	//problem is that when it has 4 numbers, it only has 2 numbers left to sort. lst_last points to 2 and sort 3 is not done correctly
	if (first > middle && first < last) //2 1 3
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
	//2 1 3 sa -> 1 2 3. 
	//3 1 2 ra -> 1 2 3
	//2 3 1 rra -> 1 2 3
	// 1 3 2 sa --> 3 1 2 ra --> 1 2 3
	//3 2 1 sa --> 2 3 1 rra --> 1 2 3

// void	sort_3(t_node **stack_a)
// {
// 	int	biggest;

// 	biggest = find_biggest_index(stack_a);
// 	if ((*stack_a)->position == biggest)
// 		ra(stack_a);
// 	else if ((*stack_a)->next->position == biggest)
// 		rra(stack_a);
// 	if ((*stack_a)->position > (*stack_a)->next->position)
// 		sa(stack_a);
// }
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
	printf("lowest sort4 is: %d\n", lowest); //delete
	print_stack(*stack_a); //delete
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
	printf("lowest sort5 is: %d\n", lowest);
	if ((*stack_a)->position == lowest)
		rra(stack_a);
	else
	{
		// if ((*stack_a)->position != lowest)
		// {
		// 	printf("does it hit?\n");
		// 	ra(stack_a);
		// }
		while ((*stack_a)->position != lowest)
			ra(stack_a);
	}
	print_stack(*stack_a);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}
// void	sort_5(t_node **stack_a, t_node **stack_b)
// {
// 	int	len;

// 	len = lst_len(*stack_a);
// 	print_stack(*stack_a);
// 	while (len--)
// 	{
// 		if ((*stack_a)->position == 0 || (*stack_a)->position == 1)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 	}
// 	sort_3(stack_a); //can also sort 2 because biggest index
// 	pa(stack_b, stack_a);
// 	pa(stack_b, stack_a);
// 	if ((*stack_a)->position > (*stack_a)->next->position)
// 		sa(stack_a);
// }

//find smallest number -> always push that to B

	//loop through nodes, push the lowest / second lowest position to b
	//if not, rotate a so the lowest position is known
	//when there is only three, sort 3
	//push a back twice (2 numbers)
	//if current position higher than next position -> swap a

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	bit;
	int	len;
	
	bit = 1;
	print_stack(*stack_a); //delete
	while (!already_sorted(stack_a))
	{
		len = lst_len(*stack_a);
		while (len)
		{
			if ((*stack_a)->position & bit)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			len--;
		}
		bit <<= 1;
		while (*stack_b)
			pa(stack_b, stack_a);
	}
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	stack_index(&(*stack_a));
	len = lst_len(*stack_a);
	if (!already_sorted(stack_a) && len == 2)
		sort_2(stack_a);
	if (!already_sorted(stack_a) && len == 3)
		sort_3(stack_a);
	else if (!already_sorted(stack_a) && len == 4)
		sort_4(stack_a, stack_b);
	else if (!already_sorted(stack_a) && len == 5)
		sort_5(stack_a, stack_b);
	else if (!already_sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_nodes(stack_a);
		free_nodes(stack_b);
	}
}

//sort 2, sort 3, sort 5