/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 17:36:59 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/04 17:24:57 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards

void	stack_index(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	current = *stack;
	temp = *stack;
	while (current)
	{
		while (temp)
		{
			if (current->value < temp->value)
				temp->position++;
			temp = temp->next;
		}
		temp = *stack;
		current = current->next;
	}
}


// void	stack_index(t_node **stack_a)
// {
// 	t_node	*current_node;
// 	t_node	*next_node;
	
// 	current_node = *stack_a;
// 	while (current_node)
// 	{
// 		next_node = *stack_a;
// 		current_node->position = 0;
// 		while (next_node)
// 		{
// 			if (current_node->value > next_node->value)
// 				next_node->position++;
// 			next_node = next_node->next;
// 		}
// 		current_node =  current_node->next;
// 		next_node = *stack_a;
// 	}
// }
		//deze checken nog. does index really hold true?
		// if (current_node->value > value)
		// 	current_node->position++;
		// current_node = current_node->next;

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
	{
		i++;
		temp = argv;
	}
	while (temp[i])
	{
		//initialise node + assign node at back
		add_lst_at_end(&stack_a, ft_ayetoi(temp[i]));
		// printf("nodes made are %d node(s) \n", lst_len(stack_a));
		i++;
	}
	//free afterwards? cuz split
	return (stack_a);
}

//initialise node through new_node
//assign new node / assign to last node
//free
