/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:27:13 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 21:51:43 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stacks_node **head, int flag)
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
		if (flag == 1)
			write(1, "rra\n", 4);
		if (flag == 2)
			write(1, "rrb\n", 4);
	}
}

void	rotate(t_stacks_node **head, int flag)
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
		if (flag == 1)
			write(1, "ra\n", 3);
		else if (flag == 2)
			write(1, "rb\n", 3);
	}
}

void	swap(t_stacks_node *head, int flag)
{
	int	temp;

	if (!head)
		return ;
	if (head->next_node)
	{
		temp = head->number;
		head->number = head->next_node->number;
		head->next_node->number = temp;
		if (flag == 1)
			write(1, "sa\n", 3);
		else if (flag == 2)
			write(1, "sb\n", 3);
	}
}

void	pb(t_stacks_node **a, t_stacks_node **b)
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
	write(1, "pb\n", 3);
}

void	pa(t_stacks_node **a, t_stacks_node **b)
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
	write(1, "pa\n", 3);
}
