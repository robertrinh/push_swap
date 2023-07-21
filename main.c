/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:16 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/07/21 16:25:21 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	input_check(argc, argv);
	stack_a = stacka_init(argc, argv);
	stack_b = NULL;
	//set the index for the stacks (in a, and also check how many nodes there are)
	//implement an ''is sorted''
	//sort the stuff
	//free afterwards?
	return (0);	
}

	// t_node	*a;
	// t_node	*b;

	// a = NULL;
	// b = NULL; //stack creation in andere functie zetten?
//digit check via bool? want je checkt gewoon true or false als je naar digit kijkt
// aangezien we heletijd first argument van argv gebruiken om input te checken -> make it a const int? can't change value



/* stappenplan:
1. build stacks
2. build actions
3. hardcore 2/3 digits
4. get the sorting algorithm */