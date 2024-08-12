/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:44:10 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 16:38:25 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stacks_node **lst)
{
	t_stacks_node	*temp;

	while (*lst)
	{
		temp = (*lst)->next_node;
		free(*lst);
		*lst = temp;
	}
}

void	off_limits(int *arr, char **str, t_stacks_node **a)
{
	ft_putstr_fd("Error\n", 2);
	free(arr);
	free_it(str);
	if (*a)
		free_stack(a);
	exit(EXIT_FAILURE);
}

void	free_double(int dup[], char **str, t_stacks_node **a)
{
	ft_putstr_fd("Error\n", 2);
	free(dup);
	free_it(str);
	if (*a)
		free_stack(a);
	exit(EXIT_FAILURE);
}

void	argerror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_it(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
