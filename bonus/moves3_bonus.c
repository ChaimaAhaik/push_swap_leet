/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:07:47 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/23 10:56:13 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

int	moves_cmp(t_list **a, t_list **b, char *p)
{
	if (ft_strcmp(p, "sa\n") == 0)
		return (sa(a), 0);
	else if (ft_strcmp(p, "sb\n") == 0)
		return (sb(b), 0);
	else if (ft_strcmp(p, "ss\n") == 0)
		return (ss(a, b), 0);
	else if (ft_strcmp(p, "pa\n") == 0)
		return (pa(a, b), 0);
	else if (ft_strcmp(p, "pb\n") == 0)
		return (pb(b, a), 0);
	else if (ft_strcmp(p, "ra\n") == 0)
		return (ra(a), 0);
	else if (ft_strcmp(p, "rb\n") == 0)
		return (rb(b), 0);
	else if (ft_strcmp(p, "rr\n") == 0)
		return (rr(a, b), 0);
	else if (ft_strcmp(p, "rra\n") == 0)
		return (rra(a), 0);
	else if (ft_strcmp(p, "rrb\n") == 0)
		return (rrb(b), 0);
	else if (ft_strcmp(p, "rrr\n") == 0)
		return (rrr(a, b), 0);
	else
		return (write(2, "Error\n", 6), 1);
}

int	moves(t_list **a, t_list **b)
{
	char	*p;

	p = get_next_line(0); 
	while (p)
	{
		if (!moves_cmp(a, b, p))
		{
			free(p);
			p = get_next_line(0);
		}
		else
			return (free(p), get_next_line(-1), 1);
	}
	return (0);
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
			ft_fill_free(ptr, i + 1);
			return (0);
		}
		ft_lstadd_back(number, ft_lstnew(content));
		i++;
	}
	ft_fill_free(ptr, i);
	return (1);
}
