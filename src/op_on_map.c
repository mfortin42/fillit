/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/15 08:41:12 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	calc_map_size(t_env *env)
{
	int		i;
	int		j;
	int		size;
	int		tmp_max;

	size = 0;
	i = -1;
	while (++i < MAP_WIDTH)
	{
		j = -1;
		while (++j < MAP_WIDTH)
			if (MAP[i][j] != 0 && (tmp_max = ft_max(i + 1, j + 1)) > size)
				size = tmp_max;
	}
	return (size);
}

static int	add_tetri_in_map2(t_env *env, int nb_tetri)
{
	replace_tetri_in_map(env, nb_tetri, 0);
	return (-1);
}

int			add_tetri_in_map(t_env *env, int nb_tetri)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_CONTENT(nb_tetri)[i][j] != '#')
				continue;
			if (TETRI_Y(nb_tetri) + i - TETRI_YS(nb_tetri) < 0
			|| TETRI_Y(nb_tetri) + i - TETRI_YS(nb_tetri) >= MAP_WIDTH
			|| TETRI_X(nb_tetri) + j - TETRI_XS(nb_tetri) < 0
			|| TETRI_X(nb_tetri) + j - TETRI_XS(nb_tetri) >= MAP_WIDTH
			|| MAP[TETRI_Y(nb_tetri) + i - TETRI_YS(nb_tetri)][TETRI_X(nb_tetri)
			+ j - TETRI_XS(nb_tetri)] != 0)
				return (add_tetri_in_map2(env, nb_tetri));
			MAP[TETRI_Y(nb_tetri) + i - TETRI_YS(nb_tetri)][TETRI_X(nb_tetri)
			+ j - TETRI_XS(nb_tetri)] = nb_tetri + '0';
		}
	}
	MAP_SIZE = calc_map_size(env);
	return (0);
}

void		replace_tetri_in_map(t_env *env, int nb_tetri, char c)
{
	int		i;
	int		j;

	nb_tetri += '0';
	i = -1;
	while (++i < MAP_WIDTH)
	{
		j = -1;
		while (++j < MAP_WIDTH)
			if (MAP[i][j] == nb_tetri)
				MAP[i][j] = c;
	}
}

void		save_map(t_env *env)
{
	int		i;

	i = -1;
	while (++i < NB_TETRI)
	{
		TETRI_SAVED[i]->x = TETRI[i]->x;
		TETRI_SAVED[i]->y = TETRI[i]->y;
		ft_memcpy(TETRI_SAVED[i]->content[0], TETRI[i]->content[0], 5);
		ft_memcpy(TETRI_SAVED[i]->content[1], TETRI[i]->content[1], 5);
		ft_memcpy(TETRI_SAVED[i]->content[2], TETRI[i]->content[2], 5);
		ft_memcpy(TETRI_SAVED[i]->content[3], TETRI[i]->content[3], 5);
	}
	SIZE_MAP_SAVED = MAP_SIZE;
}
