/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:18:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/16 17:30:09 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	digit_check(char *number)
{
	int	i;
	
	i = 0;
	if(number[i] == '-')
		i++;
	if(!ft_isalnum(number[i]))
		terminator();
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	if (ft_ayetoi(number) >  INT_MAX || ft_ayetoi(number) < INT_MIN)
		terminator();
	return (1);
}

int	input_check(char **str, t_node *a)
{
	t_node *new;
	int	i;

	i = 0;
	if (!str)
		terminator();
	while (str[i])
	{
		if(!digit_check(str[i]))
			terminator();
		//add the numbers to a new node?
		i++;
	}
}

//use bool data type for checks?