/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:18:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/22 17:24:12 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h> //delete afterwards

// static bool duplicate_check(char **argv, int argv1)
// {
	
// }

bool	input_check(char **argv, int argv1)
{
	int	i;

	i = 0;
	//if (duplicate check) -> return true?

	while (argv[argv1])
	{
		if (argv[argv1][i] == '\0')
			return (true);
		while (argv[argv1][i])
		{
			if (argv[argv1][0] == '-' && i == 0)
				i++;
			if (!ft_isdigit(argv[argv1][i]))
				i++;
			else
				return (true);
		}
		if (ft_ayetoi(argv[argv1]) > INT_MAX || ft_ayetoi(argv[argv1]) < INT_MIN)
			return (true);
		i = 0;
		argv1++;
	}
	return (false);
}
// kijk of er inputs zijn
// begin te loopen door de argv
//kijk of er negatief getal is
// kijk of er een digit is


// int	digit_check(char *number)
// {
// 	int	i;
	
// 	i = 0;
// 	if(number[i] == '-')
// 		i++;
// 	if(!ft_isalnum(number[i]))
// 		terminator();
// 	while (number[i])
// 	{
// 		if (!ft_isdigit(number[i]))
// 			return (0);
// 		i++;
// 	}
// 	if (ft_ayetoi(number) >  INT_MAX || ft_ayetoi(number) < INT_MIN)
// 		terminator();
// 	return (1);
// }


// 

// int	input_check(char **str, t_node **a)
// {
// 	t_node *new;
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		terminator();
// 	while (str[i])
// 	{
// 		if(!digit_check(str[i]))
// 			terminator();
// 		new = newnode(str[i]);//add the numbers to a new node?
// 		ft_lstadd_back(a, new);
// 		i++;
// 	}
// 	return (0);
// } 
//use bool data type for checks?