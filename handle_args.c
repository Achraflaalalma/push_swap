/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:22:13 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/19 17:17:19 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_alldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[0] == '+' || str[0] == '-') && i == 0)
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(int dup[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (dup[i] == dup[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_str(char *str, int size, char **argv, t_stacks_node **a)
{
	static int	j = 0;
	static int	*duplicates = NULL;
	static int	argc = 0;

	if (!argc)
		argc = size;
	if (!duplicates)
		duplicates = (int *)malloc(sizeof(int) * argc);
	if (!duplicates)
	{
		if (*argv)
			free_it(argv);
		exit(EXIT_FAILURE);
	}
	if (ft_alldigit(str) || (check_empty(str)))
		return (1);
	duplicates[j++] = ft_atoi(str);
	if (ft_atoi(str) == (long)INT_MAX + 1)
		off_limits(duplicates, argv, a);
	if (j == argc)
	{
		if (check_dup(duplicates, argc))
			free_double(duplicates, argv, a);
	}
	return (0);
}
