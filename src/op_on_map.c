/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/12 00:02:46 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	replace_tetri_in_map(t_env *env, int nb_tetri, char c)
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

int		add_tetri_in_map(t_env *env, int nb_tetri)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_Y(nb_tetri) + i >= MAP_WIDTH
			|| TETRI_X(nb_tetri) + j >= MAP_WIDTH
			|| MAP[TETRI_Y(nb_tetri) + i][TETRI_Y(nb_tetri) + j] != 0)
			{
				replace_tetri_in_map(env, nb_tetri, 0);
				return (-1);
			}
			if (TETRI_CONTENT(nb_tetri)[i][j] == '#')
				MAP[TETRI_Y(nb_tetri) + i][TETRI_Y(nb_tetri) + j] = nb_tetri
				+ '0';
		}
	}
ft_putendl("piece placed");	
	return (0);

//update map size (return -1 if impossible)
//return 0 if ok
//return -1 if impossible to place for any reason (out of map/already a tetri here)
}

void	save_map(t_env *env)
{
ft_putendl("map_saved");
	int		i;

	i = -1;
	while (++i < NB_TETRI)
	{
		TETRI_SAVED[i]->x = TETRI[i]->x;
		TETRI_SAVED[i]->y = TETRI[i]->y;
		TETRI_SAVED[i]->content[0] = TETRI[i]->content[0];
		TETRI_SAVED[i]->content[1] = TETRI[i]->content[1];
		TETRI_SAVED[i]->content[2] = TETRI[i]->content[2];
		TETRI_SAVED[i]->content[3] = TETRI[i]->content[3];
	}
	SIZE_MAP_SAVED = MAP_SIZE;
}
