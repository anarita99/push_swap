/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:26:42 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 14:15:14 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*tmp;

	min = a->index;
	pos = 0;
	min_pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = get_min_index_pos(*a);
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}
