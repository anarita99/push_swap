/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:26:55 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 14:13:50 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = get_min_index_pos(*a);
	while (min_pos != 0)
	{
		if (min_pos <= 2)
			ra(a);
		else
			rra(a);
		min_pos = get_min_index_pos(*a);
	}
	pb(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_3(a);
	if ((*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}
