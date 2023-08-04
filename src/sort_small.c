/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/04 17:50:15 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards

void	sort(t_node **stack_a)
{
	int	len;

	// stack_index(*stack_a);
	len = lst_len(*stack_a);
	printf("node count is (sort): %d\n", len);
	printf("it does go in here (sort) \n");
	if (!already_sorted(stack_a) && len == 2)
		sort_2(stack_a);
	else if (!already_sorted(stack_a) && len == 3)
		sort_3(stack_a);
	//else
		//big_sort (10+ en radix) (!already sorted(stack_a)) -> radix
	//stack b ook nog implementen in functie?
}
void	sort_2(t_node **stack_a)
{
	//bij 2 cijfers: 2 1. 5 3. 9 1. you need swap a
	printf("value of stack a + stack a next is: %d %d \n", (*stack_a)->value, (*stack_a)->next->value);
	if ((*stack_a)->value && (*stack_a)->next->value)
		sa(stack_a);
}
void	sort_3(t_node **stack_a)
{
	t_node	*last;
	
	last = lst_last(*stack_a);
	printf("sort 3 going in hot \n");
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->next->value < last->value) //2 1 3
		sa(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->next->value > last->value) // 3 1 2
		ra(stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->next->value > last->value) // 2 3 1
		rra(stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->next->value > last->value) //1 3 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->next->value > last->value) //3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	//2 1 3 sa -> 1 2 3. 
	//3 1 2 ra -> 1 2 3
	//2 3 1 rra -> 1 2 3
	// 1 3 2 sa --> 3 1 2 ra --> 1 2 3
	//3 2 1 sa --> 2 3 1 rra --> 1 2 3
	
}
//sort 2, sort 3, sort 5