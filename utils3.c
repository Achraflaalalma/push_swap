/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:46:37 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/16 21:46:48 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks_node	*get_max(t_stacks_node *stack)
{
	t_stacks_node	*max_node;
	int				max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next_node;
	}
	return (max_node);
}
