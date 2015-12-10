/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/10 08:18:21 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
* Delete the specified tetri in the map
*/
void	del_tetri_in_map(t_env *env, int nb_tetri)
{
	int		i;
	int		j;

	nb_tetri += 48; // ajout de 48 car int0 != char0 (voir table ascii)
	i = -1;
	while (++i < MAP_WIDTH)
	{
		j = -1;
		while (++j < MAP_WIDTH)
			if (MAP[i][j] == nb_tetri)
				MAP[i][j] = '\0';
	}
}

/*
* Add the specified tetri in the map + update map size (return -1 if impossible)
*/
int		add_tetri_in_map(t_env *env, int nb_tetri)
{
	(void)env;
	(void)nb_tetri;
	return (-1);
//add_tetri_in_map() which return 0 if ok or -1 if impossible to place for any reason (out of map/already a tetri here)
}

/*
* Save the map/map size
*/
void	save_map(t_env *env)
{
	(void)env;
//save_map() do a memcpy for each tetri + copy the map size
}
