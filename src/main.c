/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:16 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/14 21:49:12 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards


void print_stack(t_node *stack) {
    t_node *current = stack;
    while (current != NULL) {
        printf("Position: %d, Value: %d\n", current->position, current->value);
        current = current->next;
    }
}

void new_print(t_node *stack) {
    t_node *current = stack;
    while (current != NULL) {
        printf("Position: %d, Value: %d AFTER SORT\n", current->position, current->value);
        current = current->next;
    }
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	input_check(argc, argv);
	stack_a = stacka_init(argc, argv);
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	new_print(stack_a);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
	return (0);	
}
	// t_node	*a;
	// t_node	*b;

	// a = NULL;
	// b = NULL; //stack_a creation in andere functie zetten?
//digit check via bool? want je checkt gewoon true or false als je naar digit kijkt
// aangezien we heletijd first argument van argv gebruiken om input te checken -> make it a const int? can't change value

/* stappenplan:
1. build stacks
2. build actions
3. hardcore 2/3 digits
4. get the sorting algorithm */