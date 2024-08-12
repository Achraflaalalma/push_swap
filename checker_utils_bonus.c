/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:26:40 by lfrida            #+#    #+#             */
/*   Updated: 2024/01/18 22:30:20 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_rr(t_stacks_node **a, t_stacks_node **b)
{
	if (!*a && !*b)
		return ;
	checker_rotate(a);
	checker_rotate(b);
}

void	checker_rrr(t_stacks_node **a, t_stacks_node **b)
{
	if (!*a && !*b)
		return ;
	checker_rev_rotate(a);
	checker_rev_rotate(b);
}

void	checker_ss(t_stacks_node *a, t_stacks_node *b)
{
	if (!a && !b)
		return ;
	checker_swap(a);
	checker_swap(b);
}

void	checker_rev_rotate(t_stacks_node **head)
{
	t_stacks_node	*last;

	if (!*head)
		return ;
	if ((*head)->next_node)
	{
		last = ft_lstlast(*head);
		if (last->prev_node)
			last->prev_node->next_node = NULL;
		last->prev_node = NULL;
		ft_lstadd_front(head, last);
	}
}

void	checker_rotate(t_stacks_node **head)
{
	t_stacks_node	*first;
	t_stacks_node	*last;

	if (!*head)
		return ;
	first = *head;
	if (first->next_node)
	{
		*head = first->next_node;
		first->next_node = NULL;
		last = ft_lstlast(*head);
		last->next_node = first;
		first->prev_node = last;
	}
}
