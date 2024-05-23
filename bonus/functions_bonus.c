/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:43:14 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/23 10:51:54 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (dest[i] || src[i])
	{
		if (!((unsigned char)dest[i] == (unsigned char)src[i]))
			return ((unsigned char)dest[i] - (unsigned char)src[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *sttc, char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	if (!sttc && !buff)
		return (NULL);
	len = ft_strlen(sttc) + ft_strlen(buff);
	if (len == 0)
		return (free(sttc), NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (sttc && sttc[i])
	{
		ptr[i] = sttc[i];
		i++;
	}
	while (buff && buff[j])
		ptr[i++] = buff[j++];
	return (ptr[i] = '\0', free(sttc), sttc = NULL, ptr);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	ptr = (char *)malloc(1 * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	list_sorted(t_list *a, t_list *b)
{
	if (list_is_sorted(a) == 0 && ft_lstsize(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
