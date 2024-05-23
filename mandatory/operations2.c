/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:57:08 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 17:07:40 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_list **a, int flag, char c)
{
	int		swap;
	int		index_x;
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	swap = (*a)->content;
	(*a)->content = tmp->content;
	tmp->content = swap;
	index_x = (*a)->index;
	(*a)->index = tmp->index;
	tmp->index = index_x;
	if (flag == 1)
		ft_printf("s%c\n", c);
	else
		(void)c;
}

void	swap_s(t_list **a, t_list **b)
{
	swap_ab(a, 0, 'a');
	swap_ab(b, 0, 'b');
	ft_printf("ss\n");
}

void	reverse_rotab(t_list **a, int flag, char c)
{
	int		inde_x;
	int		data;
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
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
	if (flag == 1)
		ft_printf("rr%c\n", c);
	else
		(void)c;
}

void	reverse_rotr(t_list **a, t_list **b)
{
	reverse_rotab(a, 0, 'a');
	reverse_rotab(b, 0, 'b');
	ft_printf("rrr\n");
}

void	push_a(t_list **a, t_list **b, char c)
{
	int		inde_x;
	int		data;
	t_list	*tmp;

	tmp = *b;
	data = (*b)->content;
	inde_x = (*b)->index;
	(*b) = (*b)->next;
	free(tmp);
	ft_lstadd_front(a, ft_lstnew(data));
	(*a)->index = inde_x;
	ft_printf("p%c\n", c);
}
