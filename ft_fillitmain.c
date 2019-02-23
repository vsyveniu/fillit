/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillitmain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:54:45 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/12/12 17:36:04 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

void	ft_printmap(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**ft_finalmap(t_section *list, int size)
{
	char	**map;

	map = NULL;
	while (map == NULL)
	{
		map = ft_createmap(size);
		map = ft_solve(list, map);
		size++;
	}
	return (map);
}

int		ft_validation(char *checkarr)
{
	int		i;
	char	*temp;
	char	**dest;

	i = 0;
	if (!(ft_cofsymb(checkarr)))
		ft_error();
	temp = ft_strjoin("\n", checkarr);
	dest = ft_strsplit(temp, '\n');
	if (ft_vtet(dest) == -1)
		ft_error();
	free(temp);
	ft_freematrix(dest);
	return (1);
}

int		main(int argc, char **argv)
{
	int			size;
	char		*readarr;
	char		**map;
	t_section	*list;

	if (argc == 2)
	{
		readarr = ft_read(argv[1]);
		if (!(ft_validation(readarr)))
			ft_error();
		list = ft_createlist(readarr);
		ft_setchar(list);
		size = ft_getsize(readarr);
		list = ft_setcoords(list);
		map = ft_finalmap(list, size);
		ft_printmap(map);
	}
	else
		ft_usage();
	return (0);
}
