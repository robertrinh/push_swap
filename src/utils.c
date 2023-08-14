/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 16:07:07 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/14 22:23:15 by robertrinh    ########   odam.nl         */
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
int	find_lowest_index(t_node **stack_a)
{
	int	lowest_index;
	t_node *node;

	lowest_index = 0;
	node = *stack_a;
	while (node)
	{
		if (node->position < lowest_index)
			lowest_index = node->position;
		node = node->next;
	}
	return (lowest_index);
}
int	find_biggest_index(t_node **stack_a)
{
	int	biggest_index;
	t_node *node;

	biggest_index = 0;
	node = *stack_a;
	while (node)
	{
		if (node->position > biggest_index)
			biggest_index = node->position;
		node = node->next;
	}
	return (biggest_index);
}

void	free_nodes(t_node **node)
{
	t_node	*temp;

	if (!node)
		return ;
	while (*node)
	{
		temp = (*node)->next;
		if (node)
			free(node);
		node = &temp;
	}
}
