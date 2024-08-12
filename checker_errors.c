/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:06:22 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/19 15:46:36 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_buff_stacks(t_stacks_node **a, t_stacks_node **b, char *buffer)
{
	ft_putstr_fd("Error\n", 2);
	if (buffer)
		free(buffer);
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}

void	input_error(t_stacks_node **a, t_stacks_node **b)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}
