/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:58:55 by adores            #+#    #+#             */
/*   Updated: 2025/06/16 14:10:16 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	free_this_pls(t_stack *stk)
{
	t_stack	*tmp;

	if (!stk)
		return ;
	while (stk)
	{
		tmp = stk->next;
		free(stk);
		stk = tmp;
	}
}

int	ft_list_size(t_stack *stk)
{
	int	count;

	count = 0;
	if (!stk)
		return (0);
	while (stk)
	{
		count++;
		stk = stk->next;
	}
	return (count);
}
