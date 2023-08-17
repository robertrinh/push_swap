/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 16:44:56 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/08/16 23:13:25 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	bit;
	int	len;
	
	bit = 1;
	// print_stack(*stack_a); //delete
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
