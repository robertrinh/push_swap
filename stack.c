/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 17:36:59 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/22 17:54:57 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stacka_init(char **str, int argv1)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	while (str[argv1])
	{
		if (a == NULL)
			a = newnode(ft_ayetoi(str[argv1]));
	}
}