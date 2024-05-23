/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1__bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:13:09 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 17:05:03 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	index_func(t_list **a)
{
	t_list	*cmp;
	t_list	*holder;

	holder = *a;
	while ((*a) != NULL)
	{
		(*a)->index = 0;
		cmp = holder;
		while (cmp != NULL)
		{
			if ((*a)->content > cmp->content)
				(*a)->index += 1;
			cmp = cmp->next;
		}
		(*a) = (*a)->next; 
	}
	(*a) = holder;
}

int	max_number(t_list *a, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if ((a->index) > max)
			max = a->index;
		a = a->next;
		i++;
	}
	return (max);
}

int	min_number(t_list *a, int size)
{
	int	i;
	int	min;

	i = 1;
	min = a->index;
	while (i < size)
	{
		a = a->next;
		if (a->index < min)
			min = a->index;
		i++;
	}
	return (min);
}

int	ft_best_range(int size)
{
	int	range;

	range = 0.05 * size + 10;
	return (range);
}

int	max_section(t_list *b, int max, int size)
{
	while ((b != NULL) && size >= 0)
	{
		if (b->index == max)
			return (1);
		b = b->next;
		size--;
	}
	return (0);
}
