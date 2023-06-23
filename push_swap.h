/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:19 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/23 14:37:34 by qtrinh        ########   odam.nl         */
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
void	input_check(int argc, char **argv, int argv1);
bool	duplicate_check(char **argv, int argv1);
long	ft_ayetoi(const char *str);

/* linked list */
t_node *newnode(int value);
t_node *lst_last(t_node *lst);
void	lst_add_front(t_node **lst, t_node *new);
void	lst_add_back(t_node **lst, t_node *new);
int	lst_len(t_node *lst);

#endif