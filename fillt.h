/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:51:15 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/12/12 17:30:02 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLT_H
# define FILLT_H

# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct			s_section
{
	char				**str;
	char				cs;

	int					x[4];
	int					y[4];
	struct s_section	*next;
}						t_section;

int						ft_cofsymb(char *tab);
char					*ft_read(char *arv);
void					ft_error();
int						ft_vtet(char **tab);
t_section				*ft_createlist(char *str);
void					ft_setchar(t_section *list);
t_section				*ft_setcoords(t_section *list);
char					**ft_createmap(int numtet);
char					**ft_solve(t_section *list, char **map);
void					ft_usage();
void					ft_freematrix(char **tab);
int						ft_getsize(char *tab);
int						ft_validcrunch(char *tab);

#endif
