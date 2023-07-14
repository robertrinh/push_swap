/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 17:36:59 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/07/14 15:31:09 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make an index function

t_node	*stacka_init(int argc, char **argv)
{
	t_node	*stack_a;
	int	i;
	char **temp;

	i = 0;
	stack_a = NULL;
	if (argc == 2)
		temp = ft_split(argv[i], ' ');
	else
		i++;
		temp = argv;
	while (temp[i])
	{
		//initialise node + assign node at back
		add_lst_at_end(&stack_a, ft_ayetoi(temp[i]));
		i++;
	}
	//free afterwards? cuz split
	return (stack_a);
}

//initialise node through new_node
//assign new node / assign to last node
//free
