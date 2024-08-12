/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:28:36 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/19 17:40:58 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	join(const char *line, char **buffer)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
		*buffer = ft_strjoin(*buffer, "sa\n");
	else if (!(ft_strncmp(line, "sb\n", 3)))
		*buffer = ft_strjoin(*buffer, "sb\n");
	else if (!(ft_strncmp(line, "ss\n", 3)))
		*buffer = ft_strjoin(*buffer, "ss\n");
	else if (!(ft_strncmp(line, "pa\n", 3)))
		*buffer = ft_strjoin(*buffer, "pa\n");
	else if (!(ft_strncmp(line, "pb\n", 3)))
		*buffer = ft_strjoin(*buffer, "pb\n");
	else if (!(ft_strncmp(line, "ra\n", 3)))
		*buffer = ft_strjoin(*buffer, "ra\n");
	else if (!(ft_strncmp(line, "rb\n", 3)))
		*buffer = ft_strjoin(*buffer, "rb\n");
	else if (!(ft_strncmp(line, "rr\n", 3)))
		*buffer = ft_strjoin(*buffer, "rr\n");
	else if (!(ft_strncmp(line, "rra\n", 4)))
		*buffer = ft_strjoin(*buffer, "rra\n");
	else if (!(ft_strncmp(line, "rrb\n", 4)))
		*buffer = ft_strjoin(*buffer, "rrb\n");
	else if (!(ft_strncmp(line, "rrr\n", 4)))
		*buffer = ft_strjoin(*buffer, "rrr\n");
	else
		return (1);
	return (0);
}

void	handle_line(char *line, t_stacks_node **a, t_stacks_node **b)
{
	if (!(ft_strncmp(line, "sa", 2)))
		checker_swap(*a);
	else if (!(ft_strncmp(line, "sb", 2)))
		checker_swap(*b);
	else if (!(ft_strncmp(line, "ss", 2)))
		checker_ss(*a, *b);
	else if (!(ft_strncmp(line, "pa", 2)))
		checker_pa(a, b);
	else if (!(ft_strncmp(line, "pb", 2)))
		checker_pb(a, b);
	else if (!(ft_strncmp(line, "ra", 2)))
		checker_rotate(a);
	else if (!(ft_strncmp(line, "rb", 2)))
		checker_rotate(b);
	else if (!(ft_strncmp(line, "rra", 3)))
		checker_rev_rotate(a);
	else if (!(ft_strncmp(line, "rrb", 3)))
		checker_rev_rotate(b);
	else if (!(ft_strncmp(line, "rrr", 3)))
		checker_rrr(a, b);
	else if (!(ft_strncmp(line, "rr", 2)))
		checker_rr(a, b);
}

void	prompt_user(t_stacks_node **a, t_stacks_node **b)
{
	int		i;
	char	*line;
	char	*buffer;
	char	**strings;

	buffer = ft_strdup("");
	if (!buffer)
		exit(EXIT_FAILURE);
	line = get_next_line(0);
	while (line)
	{
		if (join(line, &buffer) || !buffer)
			free_buff_stacks(a, b, buffer);
		free(line);
		line = get_next_line(0);
	}
	strings = ft_split(buffer, '\n', 1);
	if (!strings)
		free_buff_stacks(a, b, buffer);
	i = 0;
	while (strings[i])
		handle_line(strings[i++], a, b);
	free_it(strings);
}

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
	prompt_user(&a, &b);
	if (checker_is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
