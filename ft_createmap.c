/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:39:45 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/12/01 12:39:48 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

t_section	*ft_coordtoeach(t_section *list, char **tab)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (tab[y] != 0)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == list->cs)
			{
				list->x[i] = x;
				list->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (list);
}

t_section	*ft_setcoords(t_section *list)
{
	t_section	*temp;
	int			i;

	i = 0;
	temp = list;
	while (temp->next != NULL)
	{
		temp = ft_coordtoeach(temp, temp->str);
		temp = temp->next;
	}
	return (list);
}

int			ft_tsqrt(unsigned int num)
{
	long i;

	i = 0;
	while (num > i * i)
		i++;
	return (i);
}

int			ft_getsize(char *tab)
{
	int i;
	int j;
	int num;

	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	j = i / 20;
	num = ft_tsqrt(4 * j);
	return (num);
}

char		**ft_createmap(int numtet)
{
	char	**dest;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!(dest = (char **)malloc(sizeof(char *) * (numtet + 1))))
		return (NULL);
	while (++i < numtet)
		if (!(dest[i] = (char *)malloc((sizeof(char)) * (numtet + 1))))
			return (NULL);
	i = 0;
	while (i < numtet)
	{
		if (j > numtet - 1)
		{
			dest[i][j] = '\0';
			j = 0;
			i++;
			continue;
		}
		dest[i][j] = '.';
		j++;
	}
	return (dest);
}
