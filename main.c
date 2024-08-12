/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:30:39 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/19 17:17:11 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks_node	*a;
	t_stacks_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]) || check_empty(argv[1]))
		argerror();
	else if (argc == 2)
		argv = ft_split(argv[1], ' ', 0);
	else if (argc != 2)
		argv = ft_split(join_str(argv + 1), 32, 1);
	if (!argv)
		exit(EXIT_FAILURE);
	init_a(&a, argv);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			swap(a, 1);
		else if (ft_lstsize(a) == 3)
			sorthree(&a);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
