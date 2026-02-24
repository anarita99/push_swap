/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:45:15 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 14:08:45 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_this_pls(t_stack *stk, int stack_size)
{
	int		index;
	t_stack	*ptr;
	t_stack	*min;
	int		min_value;

	index = 0;
	while (index < stack_size)
	{
		ptr = stk;
		min = NULL;
		min_value = INT_MAX;
		while (ptr)
		{
			if (ptr->index == -1 && ptr->value < min_value)
			{
				min_value = ptr->value;
				min = ptr;
			}
			ptr = ptr->next;
		}
		if (min)
			min->index = index;
		index++;
	}
}
