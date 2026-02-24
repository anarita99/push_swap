/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:36:04 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 14:12:35 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_nodes(t_stack **stk)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	prev = *stk;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stk;
	*stk = last;
}

void	rra(t_stack	**a)
{
	reverse_rotate_nodes(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack	**b)
{
	reverse_rotate_nodes(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_nodes(a);
	reverse_rotate_nodes(b);
	write(1, "rrr\n", 4);
}
