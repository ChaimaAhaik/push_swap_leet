/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:02:23 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 16:50:00 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_list **a)
{
	int		swap;
	int		index_x;
	t_list	*tmp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	swap = (*a)->content;
	(*a)->content = tmp->content;
	tmp->content = swap;
	index_x = (*a)->index;
	(*a)->index = tmp->index;
	tmp->index = index_x;
}

void	sb(t_list **b)
{
	int		swap;
	int		index_x;
	t_list	*tmp;

	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	swap = (*b)->content;
	(*b)->content = tmp->content;
	tmp->content = swap;
	index_x = (*b)->index;
	(*b)->index = tmp->index;
	tmp->index = index_x;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	rra(t_list **a)
{
	int		inde_x;
	int		data;
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	while (((*a)->next->next) != NULL)
		(*a) = (*a)->next;
	last = (*a)->next;
	(*a)->next = NULL;
	data = last->content;
	inde_x = last->index;
	free(last);
	*a = tmp;
	ft_lstadd_front(a, ft_lstnew(data));
	(*a)->index = inde_x;
}

void	rrb(t_list **b)
{
	int		inde_x;
	int		data;
	t_list	*tmp;
	t_list	*last;

	tmp = *b;
	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	while (((*b)->next->next) != NULL)
		(*b) = (*b)->next;
	last = (*b)->next;
	(*b)->next = NULL;
	data = last->content;
	inde_x = last->index;
	free(last);
	*b = tmp;
	ft_lstadd_front(b, ft_lstnew(data));
	(*b)->index = inde_x;
}
