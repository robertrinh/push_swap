/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/11 16:49:19 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards

void	sort_2(t_node **stack_a)
{
	//bij 2 cijfers: 2 1. 5 3. 9 1. you need swap a
	if ((*stack_a)->position > (*stack_a)->next->position)
		sa(stack_a);
}
void	sort_3(t_node **stack_a)
{
	t_node	*last;
	
	last = lst_last(*stack_a);
	printf("current 3 stack value is: %d %d %d \n", (*stack_a)->value, (*stack_a)->next->value, last->value);
	if ((*stack_a)->position > (*stack_a)->next->position && (*stack_a)->next->position < last->position)
	{
		if ((*stack_a)->position < last->position)
			sa(stack_a); // 2 1 3
		else
			ra(stack_a); //3 1 2
	}
	else if ((*stack_a)->position < (*stack_a)->next->position && (*stack_a)->next->position > last->position)
	{
		if ((*stack_a)->position < last->position) //1 3 2
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a); // 2 3 1
	}
	else if ((*stack_a)->position > (*stack_a)->next->position && (*stack_a)->next->position > last->position) // 3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
}
	//2 1 3 sa -> 1 2 3. 
	//3 1 2 ra -> 1 2 3
	//2 3 1 rra -> 1 2 3
	// 1 3 2 sa --> 3 1 2 ra --> 1 2 3
	//3 2 1 sa --> 2 3 1 rra --> 1 2 3

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = lst_len(*stack_a);
	while (len--)
	{
		if ((*stack_a)->position == 0 || (*stack_a)->position == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	if ((*stack_a)->position > (*stack_a)->next->position)
		sa(stack_a);
}

//find smallest number -> always push that to B

	//loop through nodes, push the lowest / second lowest position to b
	//if not, rotate a so the lowest position is known
	//when there is only three, sort 3
	//push a back twice (2 numbers)
	//if current position higher than next position -> swap a

// void	radix_sort(t_node **stack_a, t_node **stack_b)
// {
// 	int	bit;
// }

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	stack_index(&(*stack_a));
	print_stack(*stack_a); //delete afterwards
	len = lst_len(*stack_a);
	if (!already_sorted(stack_a) && len == 2)
		sort_2(stack_a);
	else if (!already_sorted(stack_a) && len <= 3)
		sort_3(stack_a);
	else if (!already_sorted(stack_a) && len <= 5)
		sort_5(stack_a, stack_b);
	// else if (!already_sorted(stack_a))
	// 	radix_sort(stack_a, stack_b);
	else
	{
		free_nodes(*stack_a);
		free_nodes(*stack_b);
	}
}

//sort 2, sort 3, sort 5