/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 16:07:07 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/04 17:49:26 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	terminator(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	already_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	printf("does it go in here (already sorted)\n");
	while (temp && temp->next)
	{
		if (temp->position > temp->next->position)
			return (false);
		temp = temp->next;
	}
	printf("value of temp->pos and next is (at not sorted): %d %d \n", temp->position, temp->next->position);
	printf("has not been sorted\n");
	return (true);
}
