/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/17 08:54:33 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		nb_line_with_sharp(t_env *env, int tetri)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_CONTENT(tetri)[i][j] == '#')
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

static int		nb_col_with_sharp(t_env *env, int tetri)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_CONTENT(tetri)[j][i] == '#')
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

static void		check_lines_col(t_env *env, int i)
{
	const int		nb_lines = nb_line_with_sharp(env, i);
	const int		nb_col = nb_col_with_sharp(env, i);

	if ((nb_lines == 1 && nb_col != 4)
	|| (nb_lines == 2 && nb_col != 2 && nb_col != 3)
	|| (nb_lines == 3 && nb_col != 2)
	|| (nb_lines == 4 && nb_col != 1))
		ft_exit("error");
	check_tetri3(env, i, nb_col, nb_lines);
}

static void		check_cur_pos_tetri(t_env *env, int i, int *count)
{
	if (*count < 4 && ((X < 3 && TETRI_CONTENT(i)[Y][X + 1] == '#')
	|| (X > 0 && TETRI_CONTENT(i)[Y][X - 1] == '#')
	|| (Y < 3 && TETRI_CONTENT(i)[Y + 1][X] == '#')
	|| (Y > 0 && TETRI_CONTENT(i)[Y - 1][X] == '#')))
		*count = *count + 1;
	else
		ft_exit("error");
	check_lines_col(env, i);
}

void			check_each_tetri_composition(t_env *env)
{
	int		i;
	int		count;

	i = -1;
	while (++i < NB_TETRI)
	{
		count = 0;
		Y = -1;
		while (++Y < 4)
		{
			X = -1;
			while (++X < 4)
				if (TETRI_CONTENT(i)[Y][X] == '#')
					check_cur_pos_tetri(env, i, &count);
		}
	}
}
