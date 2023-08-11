/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 16:07:07 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/11 16:06:03 by robertrinh    ########   odam.nl         */
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
	while (temp && temp->next)
	{
		if (temp->position > temp->next->position)
			return (false);
		temp = temp->next;
	}
	return (true);
}
void	free_nodes(t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	while (node)
	{
		temp = node->next;
		if (node)
			free(node);
		node = temp;
	}
}
