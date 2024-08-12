/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:19:56 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 16:16:26 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_stacks_node **a, t_stacks_node **b, int found)
{
	t_stacks_node	*temp_a;
	t_stacks_node	*temp_b;
	t_stacks_node	*match;

	temp_b = *b;
	while (temp_b)
	{
		(1 == 1) && (found = 0, temp_a = *a);
		match = get_max(*a);
		while (temp_a)
		{
			if (temp_a->number > temp_b->number
				&& temp_a->number <= match->number)
			{
				match = temp_a;
				found = 1;
			}
			temp_a = temp_a->next_node;
		}
		if (!found)
			temp_b->target_node = get_min(*a);
		else
			temp_b->target_node = match;
		temp_b = temp_b->next_node;
	}
}

t_stacks_node	*calculate_cost(t_stacks_node **a, t_stacks_node **b)
{
	t_stacks_node	*temp_b;
	t_stacks_node	*cheapest_node;
	int				cheapest;

	cheapest = INT_MAX;
	temp_b = *b;
	while (temp_b)
	{
		if (temp_b->above_median)
			temp_b->push_cost = temp_b->index;
		else
			temp_b->push_cost = ft_lstsize(*b) - temp_b->index;
		if (temp_b->target_node->above_median)
			temp_b->push_cost += temp_b->target_node->index;
		else
			temp_b->push_cost += ft_lstsize(*a) - temp_b->target_node->index;
		if (temp_b->push_cost < cheapest)
		{
			cheapest = temp_b->push_cost;
			cheapest_node = temp_b;
		}
		temp_b = temp_b->next_node;
	}
	return (cheapest_node);
}

void	rdc(t_stacks_node **a, t_stacks_node **b, t_stacks_node *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rr(a, b);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			rrr(a, b);
		else
			break ;
	}
}

void	back(t_stacks_node **a, t_stacks_node **b, t_stacks_node *cheapest_node)
{
	if (!*a || !*b || !b || !a || !cheapest_node)
		return ;
	rdc(a, b, cheapest_node);
	while (*b && (cheapest_node != *b))
	{
		if (cheapest_node->above_median)
			rotate(b, 2);
		else
			rev_rotate(b, 2);
	}
	while (*a && (cheapest_node->target_node != *a))
	{
		if (cheapest_node->target_node->above_median)
			rotate(a, 1);
		else
			rev_rotate(a, 1);
	}
}
