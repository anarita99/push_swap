/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:05:34 by adores            #+#    #+#             */
/*   Updated: 2025/06/17 11:02:19 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(int num, t_stack *stk)
{
	while (stk)
	{
		if (stk->value == num)
			return (1);
		stk = stk->next;
	}
	return (0);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

static int	check_input(const char *str, long num, t_stack *a)
{
	if (!is_number(str) || num < INT_MIN || num > INT_MAX
		|| has_duplicate((int)num, a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	parse_this_pls(int argc, char **argv, t_stack **a)
{
	int		i;
	long	num;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (check_input(argv[i], num, *a))
			return (1);
		new = ft_lstnew((int)num);
		if (!new)
			return (1);
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}
