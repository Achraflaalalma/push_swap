/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:46:18 by lfrida            #+#    #+#             */
/*   Updated: 2024/01/19 16:10:17 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexed(t_stacks_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next_node;
		i++;
	}
}

void	last_step(t_stacks_node **a, t_stacks_node **b)
{
	t_stacks_node	*min_node;
	t_stacks_node	*cheapest_node;

	while ((*b))
	{
		indexed(*a);
		indexed(*b);
		target_node(a, b, 0);
		cheapest_node = calculate_cost(a, b);
		back(a, b, cheapest_node);
		pa(a, b);
	}
	min_node = get_min(*a);
	indexed(*a);
	while ((*a)->number != min_node->number)
	{
		if (min_node->above_median)
			rotate(a, 1);
		else
			rev_rotate(a, 1);
	}
}

int	get_med(t_stacks_node **a)
{
	t_stacks_node	*temp_a;
	int				min;
	int				max;

	min = INT_MAX;
	max = INT_MIN;
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->number < min)
			min = temp_a->number;
		if (temp_a->number > max)
			max = temp_a->number;
		temp_a = temp_a->next_node;
	}
	return (min + max);
}

void	turk_sort(t_stacks_node **a, t_stacks_node **b)
{
	int				med;
	t_stacks_node	*min;

	min = get_min(*a);
	med = ft_lstsize(*a) / 2;
	if (med <= min->number)
		med = get_med(a) / 2;
	while ((ft_lstsize(*a) > 3) && !is_sorted(*a))
	{
		if ((*a)->number > med)
		{
			pb(a, b);
			rotate(b, 2);
		}
		else
			pb(a, b);
	}
	sorthree(a);
	last_step(a, b);
}
