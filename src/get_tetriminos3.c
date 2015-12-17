/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 08:41:12 by wide-aze          #+#    #+#             */
/*   Updated: 2015/12/17 09:03:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		init_tabs(int *lines, int *col)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		lines[i] = 0;
		col[i] = 0;			
	}
}

void			check_tetri3(t_env *env, int i, int nb_col, int nb_lines)
{
	int		lines[4];
	int		col[4];

	init_tabs(&lines[0], &col[0]);
	return;
	(void)env;
	(void)i;
	(void)nb_lines;
	(void)nb_col;
}
