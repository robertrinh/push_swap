/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 16:07:07 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/07/14 14:19:07 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminator(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

long	ft_ayetoi(const char *str)
{
	long int	i;
	long int	result;
	long int	neg;

	result = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (neg * result);
}
