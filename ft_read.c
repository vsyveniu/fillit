/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:42:13 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/12/11 14:42:16 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

int				ft_arrlen(int fd)
{
	char	*buff;
	int		count;

	count = 0;
	while (read(fd, &buff, 1) != 0)
		count++;
	close(fd);
	return (count);
}

char			*ft_read(char *arv)
{
	int		fd;
	int		len;
	char	*dest;
	char	buff[1];
	int		i;

	i = 0;
	if ((fd = open(arv, O_RDONLY)) == -1)
		ft_error();
	len = ft_arrlen(fd);
	if ((fd = open(arv, O_RDONLY)) == -1)
		ft_error();
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((read(fd, buff, 1) != 0))
	{
		dest[i++] = buff[0];
	}
	close(fd);
	dest[i] = '\0';
	return (dest);
}
