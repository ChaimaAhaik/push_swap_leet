/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:01:51 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/22 17:47:11 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*number;

	i = 1;
	j = 0;
	number = NULL;
	if (argc > 1)
	{
		while (i < argc && argv[i])
		{
			j = nbr(argv[i], &number);
			if (j == 0)
				return (ft_lstclear(&number, free), write(2, "Error\n", 6), 1);
			i++;
		}
		index_func(&number);
		if (list_is_sorted(number) == 1)
			my_stacks(&number);
		ft_lstclear(&number, free);
	}
	return (0);
}
