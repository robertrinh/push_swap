/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:16 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/22 17:45:21 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards

int	main(int argc, char **argv)
{
	const int	argv1 = 1;

	if (argc == 1)
	{
		printf("only argv1");
		return (0);
	}
	//	return (0); //exit_succes needs stdlib.h
	if (argc == 2 && !input_check(argv, argv1))
		terminator(); //als er geen input bij argv1. terminate
	//else
		//stacka_init
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