/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:18:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/23 14:48:58 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h> //delete afterwards

bool	duplicate_check(char **argv, int argv1)
{
	int	j;

	j = 0;
	// printf("value of argv[argv1][i] is %c \n", argv[argv1][i]);
	while (argv[argv1] && argv[argv1][j + 1])
	{
		j = argv1 + 1;
		// printf("value of argv1 is: %s \n", argv[argv1]);
		// printf("value of j = %d \n", j);
		while (argv[j])
		{
			if (j == argv1)
				j++;
			if (ft_ayetoi(argv[argv1]) == ft_ayetoi(argv[j]))
			{
				printf("does it come here? dupes??");
				return (true);
			}
			j++;
		}
		argv1++;
	}
	return (false);
}

void	input_check(int argc, char **argv, int argv1)
{
	int	j;

	while (argv1 - 1 < argc - 1)
	{
		j = 0;
		printf("wat is argv[argv1]: %s, is toch een string \n", argv[argv1]);
		if (ft_ayetoi(argv[argv1] > INT_MAX || ft_ayetoi(argv[argv1] < INT_MIN)))
			terminator();
		while (argv[argv1][j])
		{
			if (!ft_isdigit(argv[argv1][j] && argv[argv1][j] != '-'))
				terminator();
			if (argv[argv1][j] == '-' && argv[argv1][j + 1] == '\0')
				terminator();
			if (argv[argv1][j] == '-' && argv[argv1][j + 1] == '-')
				terminator();
			j++;
		}
		argv1++;
	}
}
// bool	input_check(char **argv, int argv1)
// {
// 	int	i;

// 	i = 0;
	
// 	// printf("argv1 input is: %d \n", argv1);
// 	// if (duplicate_check(argv,argv1))
// 	// {
// 	// 	printf("it's false!");
// 	// 	return (terminator());
// 	// }
// 	while (argv[argv1])
// 	{
// 		if (argv[argv1][i] == '\0')
// 			return (true);
// 		while (argv[argv1][i])
// 		{
// 			if (argv[argv1][0] == '-' && i == 0)
// 				i++;
// 			if (!ft_isdigit(argv[argv1][i]))
// 				i++;
// 			else
// 				return (true);
// 		}
// 		if (ft_ayetoi(argv[argv1]) > INT_MAX
// 			|| ft_ayetoi(argv[argv1]) < INT_MIN)
// 			return (true);
// 		i = 0;
// 		argv1++;
// 	}
// 	return (false);
// }
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