/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:47:49 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 19:06:32 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_str(char **str)
{
	int		i;
	char	*join;

	join = ft_strdup("");
	if (!join)
	{
		free_it(str);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str[i])
	{
		if (check_empty(str[i]))
		{
			free(join);
			argerror();
		}
		join = ft_strjoin(join, str[i]);
		join = ft_strjoin(join, " ");
		i++;
	}
	return (join);
}

t_stacks_node	*get_min(t_stacks_node *stack)
{
	t_stacks_node	*min_node;
	int				min;

	min_node = NULL;
	min = INT_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next_node;
	}
	return (min_node);
}

void	init_a(t_stacks_node **a, char **argv)
{
	int				i;
	int				size;
	int				nbr;
	t_stacks_node	*node;

	size = 0;
	while (argv[size])
		size++;
	i = 0;
	while (argv[i])
	{
		if (check_str(argv[i], size, argv, a))
		{
			free_it(argv);
			if (*a)
				free_stack(a);
			argerror();
		}
		nbr = ft_atoi(argv[i]);
		node = ft_lstnew(&nbr);
		ft_lstadd_back(a, node);
		i++;
	}
	free_it(argv);
}
