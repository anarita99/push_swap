/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:34:42 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 10:41:53 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_nodes(t_stack **stk)
{
	t_stack	*first;
	t_stack	*last;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	first = *stk;
	*stk = first->next;
	last = ft_lstlast(*stk);
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack	**a)
{
	rotate_nodes(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack	**b)
{
	rotate_nodes(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_nodes(a);
	rotate_nodes(b);
	write(1, "rr\n", 3);
}
