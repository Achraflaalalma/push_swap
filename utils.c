/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:24:46 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 21:52:25 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stacks_node **a, t_stacks_node **b)
{
	if (!*a && !*b)
		return ;
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	rrr(t_stacks_node **a, t_stacks_node **b)
{
	if (!*a && !*b)
		return ;
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	write(1, "rrr\n", 4);
}

void	ss(t_stacks_node *a, t_stacks_node *b)
{
	if (!a && !b)
		return ;
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}

int	is_sorted(t_stacks_node *head)
{
	while (head && head->next_node)
	{
		if (head->number > head->next_node->number)
			return (false);
		head = head->next_node;
	}
	return (true);
}

void	sorthree(t_stacks_node **a)
{
	t_stacks_node	*max_node;

	if (!a || !*a)
		return ;
	max_node = get_max(*a);
	if (max_node == *a)
		rotate(a, 1);
	else if ((*a)->next_node == max_node)
		rev_rotate(a, 1);
	if ((*a)->number > (*a)->next_node->number)
		swap(*a, true);
}
