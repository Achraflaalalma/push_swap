/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:04:07 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/16 21:27:26 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stacks_node **lst, t_stacks_node *new)
{
	if (lst && new)
	{
		new->next_node = *lst;
		if (*lst != NULL)
			(*lst)->prev_node = new;
	}
	if (new)
		*lst = new;
}

t_stacks_node	*ft_lstlast(t_stacks_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next_node)
		lst = lst->next_node;
	return (lst);
}

int	ft_lstsize(t_stacks_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next_node;
	}
	return (size);
}

t_stacks_node	*ft_lstnew(int *nbr)
{
	t_stacks_node	*new_node;

	new_node = (t_stacks_node *)malloc(sizeof(t_stacks_node));
	if (!new_node)
		return (NULL);
	new_node->number = *nbr;
	new_node->next_node = NULL;
	new_node->prev_node = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_stacks_node **lst, t_stacks_node *new)
{
	t_stacks_node	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	if (*lst)
	{
		while (temp->next_node)
			temp = temp->next_node;
		temp->next_node = new;
		new->prev_node = temp;
	}
	else
		*lst = new;
}
