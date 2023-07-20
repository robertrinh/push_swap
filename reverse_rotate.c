/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 16:48:38 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/07/20 17:33:29 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Shift down all elements of a stack by 1.
The last element becomes the first one. */
void	reverse_rotate(t_node **stack)
{
	t_node *current;
	t_node *tail;
	
	if (!*stack || !(*stack)->next)
		return ;
	current = (*stack)->next; //second element of stack
	tail = *stack; //first element of stack
	while (current->next) 
	{
		tail = current; //in loop, tail updates to current
		current = current->next; //checks the last node
	}
	current->next = *stack; //set pointer next to current value of stack
	*stack = current; //assigns stack to last node
	tail->next = NULL; //assigns new tail
}
void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}
void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
