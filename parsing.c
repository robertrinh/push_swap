/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:18:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/07/21 15:49:36 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h> //delete afterwards

static bool	duplicate_check(char **temp_array)
{
	int	i;
	int	j;
	
	i = 0;
	while (temp_array[i])
	{
		j = i + 1;
		while (temp_array[j])
		{
			if (ft_ayetoi(temp_array[i]) == ft_ayetoi(temp_array[j]))
				return(true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	number_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	//check nog alleen de minus only?
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

void	input_check(int argc, char **argv)
{
	char	**temp_array;
	long	temp_argv;
	int		i;

	i = 0;
	if (argc == 2)
	{	
		printf("argv[1] is %s \n", argv[1]);
		temp_array = ft_split(argv[1], ' ');
	}
	else
		temp_array = argv + 1;
	while (temp_array[i])
	{
		// printf("temp_argv before ayetoi is %s \n", temp_array[i]);
		temp_argv = ft_ayetoi(temp_array[i]);
		// printf("temp_argv is %li \n", temp_argv);
		if (temp_argv > INT_MAX || temp_argv < INT_MIN)
			terminator();
		if (duplicate_check(temp_array))
			terminator();
		if (!number_check(temp_array[i]))
			terminator();
		i++;
	}
	//free afterwards?
}
// while (i - 1 < argc - 1)
// {
// 	j = 0;
// 	printf("wat is argv[i]: %s, is toch een string \n", argv[i]);
// 	if (ft_ayetoi(argv[i] > INT_MAX || ft_ayetoi(argv[i] < INT_MIN)))
// 		terminator();
// 	while (argv[i][j])
// 	{
// 		if (!ft_isdigit(argv[i][j] && argv[i][j] != '-'))
// 			terminator();
// 		if (argv[i][j] == '-' && argv[i][j + 1] == '\0')
// 			terminator();
// 		if (argv[i][j] == '-' && argv[i][j + 1] == '-')
// 			terminator();
// 		j++;
// 	}
// 	i++;
// } OLD INPUT CHECK, KIJK ER NOG NAAR

// bool	input_check(char **argv, int i)
// {
// 	int	i;

// 	i = 0;

// 	// printf("i input is: %d \n", i);
// 	// if (duplicate_check(argv,i))
// 	// {
// 	// 	printf("it's false!");
// 	// 	return (terminator());
// 	// }
// 	while (argv[i])
// 	{
// 		if (argv[i][i] == '\0')
// 			return (true);
// 		while (argv[i][i])
// 		{
// 			if (argv[i][0] == '-' && i == 0)
// 				i++;
// 			if (!ft_isdigit(argv[i][i]))
// 				i++;
// 			else
// 				return (true);
// 		}
// 		if (ft_ayetoi(argv[i]) > INT_MAX
// 			|| ft_ayetoi(argv[i]) < INT_MIN)
// 			return (true);
// 		i = 0;
// 		i++;
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