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

static void		fill_tabs(t_env *env, int tetri, int *lines, int *col)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_CONTENT(tetri)[i][j] == '#')
			{
				col[j] = 1;
				lines[i] = 1;
			}
		}
	}
}

static int		search_first(int *tab)
{
	if (tab[0])
		return (0);
	if (tab[1])
		return (1);
	if (tab[2])
		return (2);
	return (3);
}

void			check_tetri3(t_env *env, int i, int nb_col, int nb_lines)
{
	int		lines[4];
	int		col[4];
	int		first;

	init_tabs(&lines[0], &col[0]);
	fill_tabs(env, i, &lines[0], &col[0]);
	first = search_first(&col[0]);
	if (nb_col == 2 && (first > 2 || !col[first + 1]))
		ft_exit("error");
	if (nb_col == 3 && (first > 1 || !col[first + 1] || !col[first + 2]))
		ft_exit("error");
	first = search_first(&lines[0]);
	if (nb_lines == 2 && (first > 2 || !lines[first + 1]))
		ft_exit("error");
	if (nb_lines == 3 && (first > 1 || !lines[first + 1] || !lines[first + 2]))
		ft_exit("error");
}
