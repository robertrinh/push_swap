/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:16:27 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/23 15:05:01 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *newnode(int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->position = -1;
	// newnode->previous = NULL; nodig?
	newnode->next = NULL;
	return (newnode);
}

/* returns last node of the list */
t_node *lst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* adds node ''new'' at beginning of the list */
void	lst_add_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}
/* returns last node of the list */
void	lst_add_back(t_node **lst, t_node *new)
{
	t_node *temp;
	
	temp = *lst;
	if (!(*lst))
		*lst = new;
	else
		temp = lst_last(*lst);
		temp->next = new;
}
/* counts number of nodes in list */
int	lst_len(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}