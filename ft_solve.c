/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:16:18 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/12/01 13:16:22 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

int			ft_checkmap(t_section *list, char **map)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (list->y[i] == y && list->x[i] == x && map[y][x] != '.')
			{
				return (0);
			}
			if (list->y[i] == y && list->x[i] == x)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

t_section	*ft_setnewcoords(t_section *list, int y, int x)
{
	int	i;
	int	ydef;
	int	xdef;

	i = 0;
	ydef = list->y[i];
	xdef = list->x[i];
	while (i < 4)
	{
		list->y[i] = list->y[i] - ydef + y;
		list->x[i] = list->x[i] - xdef + x;
		i++;
	}
	return (list);
}

char		**ft_writetomap(t_section *list, char **map)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (list->x[i] == x && list->y[i] == y)
			{
				map[y][x] = list->cs;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

char		**ft_clearmap(t_section *list, char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == list->cs)
			{
				map[y][x] = '.';
			}
			x++;
		}
		y++;
	}
	return (map);
}

char		**ft_solve(t_section *list, char **map)
{
	int		y;
	int		x;
	char	**tmp;

	y = 0;
	if (list->next == NULL)
		return (map);
	tmp = NULL;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			list = ft_setnewcoords(list, y, x);
			map = ft_clearmap(list, map);
			if (ft_checkmap(list, map) == 1)
				tmp = ft_solve(list->next, ft_writetomap(list, map));
			if (tmp != NULL)
				return (tmp);
			x++;
		}
		y++;
	}
	return (tmp);
}
