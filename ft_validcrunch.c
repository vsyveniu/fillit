/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validcrunch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:55:42 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/12/12 16:55:46 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

int	ft_validcrunch(char *tab)
{
	int		i;

	i = 20;
	while (tab[i] != 0)
	{
		if (tab[i] != '\n' && tab)
		{
			ft_error();
		}
		i = i + 21;
	}
	return (1);
}
