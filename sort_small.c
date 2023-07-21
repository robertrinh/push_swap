/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/07/21 15:21:39 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	
}
void	sort_2(t_node **stack_a)
{
	//bij 2 cijfers: 2 1. 5 3. 9 1. you need swap a
	if ((*stack_a)->value && (*stack_a)->next->value)
		sa(stack_a);
}
//sort 2, sort 3, sort 5