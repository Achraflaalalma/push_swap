/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:45:27 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 21:54:39 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_swap(t_stacks_node *head)
{
	int	temp;

	if (!head)
		return ;
	if (head->next_node)
	{
		temp = head->number;
		head->number = head->next_node->number;
		head->next_node->number = temp;
	}
}

void	checker_pb(t_stacks_node **a, t_stacks_node **b)
{
	t_stacks_node	*first;

	if (!*a)
		return ;
	first = *a;
	if (first->next_node)
	{
		first->next_node->prev_node = NULL;
		*a = first->next_node;
		first->next_node = NULL;
		ft_lstadd_front(b, first);
	}
	else
	{
		ft_lstadd_front(b, first);
		*a = NULL;
	}
}

void	checker_pa(t_stacks_node **a, t_stacks_node **b)
{
	t_stacks_node	*first;

	if (!*b)
		return ;
	first = *b;
	if (first->next_node)
	{
		first->next_node->prev_node = NULL;
		*b = first->next_node;
		first->next_node = NULL;
		ft_lstadd_front(a, first);
	}
	else
	{
		ft_lstadd_front(a, first);
		*b = NULL;
	}
}

int	checker_is_sorted(t_stacks_node *head)
{
	while (head && head->next_node)
	{
		if (head->number > head->next_node->number)
			return (false);
		head = head->next_node;
	}
	return (true);
}
