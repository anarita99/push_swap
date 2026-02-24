/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:49:07 by adores            #+#    #+#             */
/*   Updated: 2025/06/17 11:39:09 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	do_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		radix_sort(a, b, size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (parse_this_pls(argc, argv, &a) == 0)
	{
		if (!is_sorted(a))
		{
			assign_this_pls(a, ft_list_size(a));
			size = ft_list_size(a);
			do_sort(&a, &b, size);
		}
	}
	free_this_pls(a);
	if (b)
		free_this_pls(b);
	return (0);
}
