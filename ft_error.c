/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:10:50 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/21 10:10:52 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

void	ft_usage(void)
{
	write(1, "	usage: ./fillit target file\n", 29);
	write(1, "	if you run the program without one or with more than", 50);
	write(1, " one arguments, the program should display an error\n", 50);
	exit(0);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
