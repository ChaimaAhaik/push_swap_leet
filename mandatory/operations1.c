/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:54:59 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/26 09:04:20 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_list **a, int flag, char c)
{
	int		l_index;
	int		data;
	t_list	*tmp;

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
	if (flag == 1)
		ft_printf("r%c\n", c);
	else
		(void)c;
}

void	rotate_r(t_list **a, t_list **b)
{
	rotate_ab(a, 0, 'a');
	rotate_ab(b, 0, 'b');
	ft_printf("rr\n");
}

void	push_to_b(t_list **a, t_list **b, int range_l)
{
	int	min;
	int	max;

	min = 0;
	while ((*a) != NULL)
	{
		max = range_l + min;
		if ((*a)->index < min)
		{
			push_a(b, a, 'b');
			rotate_ab(b, 1, 'b');
			min = min + 1;
		}
		else if ((*a)->index >= min && (*a)->index <= max)
		{
			push_a(b, a, 'b');
			min = min + 1;
		}
		else
			rotate_ab(a, 1, 'a');
	}
}

int	list_is_sorted(t_list *a)
{
	while ((a)->next != NULL)
	{
		if ((a)->index < (a)->next->index)
			(a) = (a)->next;
		else
			return (1);
	}
	return (0);
}

int	nbr(char *str, t_list **number)
{
	int		i;
	char	**ptr;
	int		content;
	int		err;

	i = 0;
	err = 0;
	if (!str[i] || check_for_char(str) == 1)
		return (0);
	ptr = ft_split(str, ' ');
	while (ptr[i] != NULL)
	{
		content = ft_atoi(ptr[i], &err);
		if (check_input(*number, content) == 1 || (err == 1))
		{
			ft_free_all(ptr, i);
			return (0);
		}
		ft_lstadd_back(number, ft_lstnew(content));
		i++;
	}
	ft_fill_free(ptr, i);
	return (1);
}
