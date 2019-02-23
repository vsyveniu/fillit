/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:25:34 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/20 10:25:36 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

int		ft_cofsymb(char *tab)
{
	int		counthash;
	int		dotcount;
	int		newlinecount;

	counthash = 0;
	dotcount = 0;
	newlinecount = 0;
	if (!(ft_validcrunch(tab)))
		ft_error();
	while (*tab != '\0')
	{
		if (*tab != '#' && *tab != '.' && *tab != '\n')
			ft_error();
		if (*tab == '#')
			counthash++;
		else if (*tab == '.')
			dotcount++;
		else if (*tab == '\n')
			newlinecount++;
		tab++;
	}
	if (counthash % 4 || dotcount % 4 || (newlinecount + 1) % 5)
		ft_error();
	return (1);
}

int		ft_crunch(char **str, int i, int j, int c)
{
	if (i > 0 && i % 4 != 0 && str[i - 1][j] == '#')
		c++;
	if (i % 4 != 3 && str[i + 1][j] == '#')
		c++;
	if (((j - 1) >= 0) && str[i][j - 1] == '#')
		c++;
	if ((j + 1) && str[i][j + 1] == '#')
		c++;
	return (c);
}

int		ft_coucon(char **str, int i)
{
	int j;
	int c;

	j = 0;
	c = 0;
	while (str[i][j])
	{
		if (str[i][j] == '#')
		{
			c = ft_crunch(str, i, j, c);
		}
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
		if (i % 4 == 0 && j == 0)
			break ;
	}
	return (c);
}

int		ft_counlines(char **tab)
{
	int i;

	i = 0;
	if (!tab || !*tab || !**tab)
		return (0);
	while (tab[i] && tab[i][0] != '\0')
		i++;
	return (i);
}

int		ft_vtet(char **tab)
{
	int		i;
	int		q;
	int		lw;

	q = ft_counlines(tab);
	i = 0;
	lw = 0;
	while (*(tab + i) && i < q)
	{
		if ((lw = ft_coucon(tab, i)) != 6)
			if (lw != 8)
				return (-1);
		i += 4;
	}
	return (0);
}
