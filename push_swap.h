/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:27:58 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/19 15:46:55 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "stdbool.h"
# include "stdio.h"

typedef struct s_stacks_node
{
	int						number;
	int						index;
	int						push_cost;
	bool					above_median;
	struct s_stacks_node	*target_node;
	struct s_stacks_node	*next_node;
	struct s_stacks_node	*prev_node;

}	t_stacks_node;

typedef struct s_var
{
	t_stacks_node	*temp_b;
	t_stacks_node	*cheapest_node;
	int				lenght_a;
	int				lenght_b;
	int				cheapest;
	int				total_cost;

}	t_var;

int				check_str(char *str, int size, char **argv, t_stacks_node **a);
void			argerror(void);
void			ft_lstadd_back(t_stacks_node **lst, t_stacks_node *new);
void			ft_lstadd_front(t_stacks_node **lst, t_stacks_node *new);
int				ft_lstsize(t_stacks_node *lst);
int				is_sorted(t_stacks_node *head);
void			sorthree(t_stacks_node **head);
void			swap(t_stacks_node *head, int flag);
void			ss(t_stacks_node *a, t_stacks_node *b);
void			pb(t_stacks_node **a, t_stacks_node **b);
void			pa(t_stacks_node **a, t_stacks_node **b);
void			rotate(t_stacks_node **head, int flag);
void			rr(t_stacks_node **a, t_stacks_node **b);
void			rev_rotate(t_stacks_node **head, int flag);
void			rrr(t_stacks_node **a, t_stacks_node **b);
void			init_a(t_stacks_node **a, char **arg);
void			turk_sort(t_stacks_node **a, t_stacks_node **b);
void			indexed(t_stacks_node *stack);
int				check_empty(char *str);
void			free_it(char **str);
void			free_stack(t_stacks_node **lst);
t_stacks_node	*get_min(t_stacks_node *stack);
t_stacks_node	*ft_lstlast(t_stacks_node *lst);
t_stacks_node	*ft_lstnew(int *nbr);
char			*join_str(char **str);
void			off_limits(int *arr, char **str, t_stacks_node **a);
void			free_double(int dup[], char **str, t_stacks_node **a);
t_stacks_node	*get_max(t_stacks_node *stack);
int				get_med(t_stacks_node **a);
void			turk_sort(t_stacks_node **a, t_stacks_node **b);
t_stacks_node	*calculate_cost(t_stacks_node **a, t_stacks_node **b);
void			back(t_stacks_node **a, t_stacks_node **b,
					t_stacks_node *cheapest_node);
void			target_node(t_stacks_node **a, t_stacks_node **b, int found);
void			checker_rr(t_stacks_node **a, t_stacks_node **b);
void			checker_rrr(t_stacks_node **a, t_stacks_node **b);
void			checker_ss(t_stacks_node *a, t_stacks_node *b);
void			checker_rev_rotate(t_stacks_node **head);
void			checker_rotate(t_stacks_node **head);
void			checker_swap(t_stacks_node *head);
void			checker_pb(t_stacks_node **a, t_stacks_node **b);
void			checker_pa(t_stacks_node **a, t_stacks_node **b);
int				checker_is_sorted(t_stacks_node *head);
void			free_buff_stacks(t_stacks_node **a,
					t_stacks_node **b, char *buffer);
void			input_error(t_stacks_node **a, t_stacks_node **b);
#endif