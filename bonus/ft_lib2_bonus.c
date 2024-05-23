/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:11:12 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 17:50:30 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	int	check(int original, int copy, int sign)
{
	if ((copy > original && sign == 1) || (copy < original && sign == -1))
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *err)
{
	size_t	i;
	int		sign;
	int		number;
	int		copy;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		copy = number;
		number = (number * 10) + sign * (str[i] - '0');
		if (check(number, copy, sign) == 1)
			return ((*err) = 1, 1);
		i++;
	}
	return (number);
}

static size_t	ft_count(char *str, char c)
{
	size_t	counter;
	size_t	i;
	size_t	substring;

	i = 0;
	counter = 0;
	while (str[i])
	{
		substring = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (substring == 0)
			{
				counter++;
				substring++;
			}
			i++;
		}
	}
	return (counter);
}

int	ft_fill_free(char **t, size_t index)
{
	size_t	j;

	j = 0;
	if (!t[index])
	{
		while (j < index)
		{
			free(t[j]);
			j++;
		}
		free(t);
		return (1);
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**t;
	t_help	nb;

	nb.i = 0;
	nb.index = 0;
	if (!s)
		return (NULL);
	t = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	t[ft_count(s, c)] = NULL;
	while (s[nb.i] && nb.i < ft_strlen(s) && nb.index < ft_count(s, c))
	{
		while (s[nb.i] == c && s[nb.i])
			nb.i++;
		nb.start = nb.i;
		while (s[nb.i] != c && s[nb.i])
			nb.i++;
		t[nb.index] = ft_substr(s, nb.start, nb.i - nb.start);
		if (ft_fill_free(t, nb.index) == 1)
			return (NULL);
		nb.index++;
	}
	return (t);
}
