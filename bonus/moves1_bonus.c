/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:52:42 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 16:50:05 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list **a)
{
	int		l_index;
	int		data;
	t_list	*tmp;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	data = (*a)->content;
	l_index = (*a)->index;
	tmp = (*a);
	(*a) = (*a)->next;
	free(tmp);
	tmp = (*a);
	ft_lstadd_back(a, ft_lstnew(data));
	while ((*a)->next != NULL)
		(*a) = (*a)->next;
	(*a)->index = l_index;
	(*a) = tmp;
}

void	rb(t_list **b)
{
	int		l_index;
	int		data;
	t_list	*tmp;

	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	data = (*b)->content;
	l_index = (*b)->index;
	tmp = (*b);
	(*b) = (*b)->next;
	free(tmp);
	tmp = (*b);
	ft_lstadd_back(b, ft_lstnew(data));
	while ((*b)->next != NULL)
		(*b) = (*b)->next;
	(*b)->index = l_index;
	(*b) = tmp;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	pa(t_list **a, t_list **b)
{
	int		inde_x;
	int		data;
	t_list	*tmp;

	if (b == NULL || (*b) == NULL)
		return ;
	tmp = *b;
	data = (*b)->content;
	inde_x = (*b)->index;
	(*b) = (*b)->next;
	free(tmp);
	ft_lstadd_front(a, ft_lstnew(data));
	(*a)->index = inde_x;
}

void	pb(t_list **b, t_list **a)
{
	int		inde_x;
	int		data;
	t_list	*tmp;

	if (a == NULL || (*a) == NULL)
		return ;
	tmp = *a;
	data = (*a)->content;
	inde_x = (*a)->index;
	(*a) = (*a)->next;
	free(tmp);
	ft_lstadd_front(b, ft_lstnew(data));
	(*b)->index = inde_x;
}
