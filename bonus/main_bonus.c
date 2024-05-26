/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:51:02 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/26 09:16:41 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*a;
	t_list	*b;

	i = 1;
	j = 0;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		while (i < argc && argv[i])
		{
			j = nbr(argv[i], &a);
			if (j == 0)
				return (ft_lstclear(&a), write(2, "Error\n", 6), 1);
			i++;
		}
		index_func(&a);
		if (moves(&a, &b) == 0)
			list_sorted(a, b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
