/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:58:40 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 14:16:08 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_nodes(t_stack	**stk)
{
	t_stack	*first;
	t_stack	*second;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	first = *stk;
	second = first -> next;
	first->next = second ->next;
	second->next = first;
	*stk = second;
}

void	sa(t_stack **a)
{
	swap_nodes(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_nodes(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_nodes(a);
	swap_nodes(b);
	write(1, "ss\n", 3);
}
