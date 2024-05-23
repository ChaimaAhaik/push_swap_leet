/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:18:08 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 17:03:40 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	space_checker(char *str, int i)
{
	while (str[i] && ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

int	sign_checker(char *str, int i, char c, char a)
{
	int	j;

	j = i - 1;
	if ((str[j] == c || str[j] == a) && !(str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
}

int	check_for_char(char *str)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (str[i])
	{
		i = space_checker(str, i);
		if (!str[i] && found == 0)
			return (1);
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
		{
			if (str[i] >= '0' && str[i] <= '9')
				found++;
			i++;
			if (sign_checker(str, i, '-', '+') == 1)
				return (1);
		}
		else
		{
			if (str[i] != '\0')
				return (1);
		}
	}
	return (0);
}

int	check_input(t_list *lst, int nbr)
{
	while (lst != NULL)
	{
		if (lst->content == nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}
