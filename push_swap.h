/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:19 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/16 17:28:31 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* malloc, free, bool */
# include <stdlib.h> 
# include <stdbool.h>

/* libft */
# include "libft/libft.h"

typedef struct s_node
{
	int	value;
	int	position;
	struct s_node *previous;
	struct s_node *next;
}	t_node;

int	main(int argc, char **argv);
void	terminator(void);

#endif