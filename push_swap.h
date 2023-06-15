/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:19 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/15 14:54:48 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* malloc, free */
# include <stdlib.h> 

/* libft */
# include "libft/libft.h"

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node *previous;
	struct s_node *next;
}	t_node;

int	main(int argc, char **argv);

#endif