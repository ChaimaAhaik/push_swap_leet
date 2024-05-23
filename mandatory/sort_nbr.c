/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:07:24 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 17:43:47 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_2(t_list **a, int size)
{
	if (size > 1)
	{
		if ((*a)->index > (*a)->next->index)
			swap_ab(a, 1, 'a');
	}
}

void	stack_3(t_list **a)
{
	int	max;
	int	min;

	max = max_number(*a, 3);
	min = min_number(*a, 3);
	if (((*a)->index) == max)
	{
		rotate_ab(a, 1, 'a');
		if ((*a)->index != min)
			swap_ab(a, 1, 'a');
	}
	else if (((*a)->index) != min)
	{
		if (((*a)->next->index) == min)
			swap_ab(a, 1, 'a');
		else
			reverse_rotab(a, 1, 'a');
	}
	else if ((*a)->next->index == max)
	{
		swap_ab(a, 1, 'a');
		rotate_ab(a, 1, 'a');
	}
}

void	stack_5(t_list **a, t_list **b)
{
	int	size;
	int	min;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		min = min_number(*a, size);
		if (max_section(*a, min, size / 2) == 1)
		{
			while ((*a)->index != min)
				rotate_ab(a, 1, 'a');
			push_a(b, a, 'b');
		}
		else
		{
			while ((*a)->index != min)
				reverse_rotab(a, 1, 'a');
			push_a(b, a, 'b');
		}
		size--;
	}
	stack_3(a);
	while ((*b) != NULL)
		push_a(a, b, 'a');
}

void	push_sorting(t_list **a, t_list **b)
{
	int	max;
	int	found;

	while ((*b))
	{
		max = max_number(*b, ft_lstsize(*b));
		found = max_section(*b, max, (ft_lstsize(*b) / 2));
		if (found == 1)
		{
			while ((*b)->index != max)
				rotate_ab(b, 1, 'b');
		}
		else
		{
			while ((*b)->index != max)
				reverse_rotab(b, 1, 'b');
		}
		push_a(a, b, 'a');
	}
}

void	my_stacks(t_list **a)
{
	int		size_a;
	t_list	*b;

	b = NULL;
	size_a = ft_lstsize(*a);
	if (size_a == 1 || size_a == 2)
		stack_2(a, size_a);
	else if (size_a == 3)
		stack_3(a);
	else if (size_a == 4 || size_a == 5)
		stack_5(a, &b);
	else
	{
		push_to_b(a, &b, ft_best_range(size_a));
		push_sorting(a, &b);
	}
}
