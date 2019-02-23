/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:09:11 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/28 12:09:13 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

char		**ft_createlistnode(char *tab, int index)
{
	char	**dest;
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tmp = ft_strsub(tab, index, 20);
	dest = ft_strsplit(tmp, '\n');
	return (dest);
}

int			ft_listlen(char *tab)
{
	int i;

	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	return (i);
}

char		*ft_setalpha(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = str;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			dest[i] = c;
		}
		i++;
	}
	return (dest);
}

void		ft_setchar(t_section *list)
{
	int i;
	int j;

	i = 0;
	while (list->next != NULL)
	{
		j = 0;
		while (list->str[j] != 0)
		{
			ft_setalpha(list->str[j], list->cs);
			j++;
		}
		list = list->next;
		i++;
	}
}

t_section	*ft_createlist(char *tab)
{
	t_section	*list;
	t_section	*tls;
	int			len;
	int			i;
	char		s;

	i = 0;
	s = 65;
	tab = ft_strjoin("\n", tab);
	len = (ft_listlen(tab) / 20);
	if (!(list = (t_section*)malloc(sizeof(t_section))))
		return (NULL);
	tls = list;
	while (len-- > 0)
	{
		tls->str = ft_createlistnode(tab, i);
		tls->cs = s;
		if (!(tls->next = (t_section*)malloc(sizeof(t_section))))
			return (NULL);
		tls = tls->next;
		i += 21;
		s++;
	}
	return (list);
}
