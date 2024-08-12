/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrida <lfrida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:23:44 by alaalalm          #+#    #+#             */
/*   Updated: 2024/01/18 02:00:08 by lfrida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	check_num(long *numbers, int *msigns)
{
	if ((*numbers * *msigns) < INT_MIN || (*numbers * *msigns) > INT_MAX)
		return (2147483648);
	return (*numbers * *msigns);
}

long	ft_atoi(const char *str)
{
	long	numbers;
	t_vars	var;

	numbers = 0;
	var.msigns = 1;
	var.count = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			var.msigns = -var.msigns;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		numbers = numbers * 10 + (*str - 48);
		str++;
		var.count++;
	}
	if (var.count > 10)
		return (2147483648);
	return (check_num(&numbers, &var.msigns));
}
