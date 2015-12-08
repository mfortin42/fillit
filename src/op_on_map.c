/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/08 01:00:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Delete the specified tetri in the map
*/
void	del_tetri_in_map(t_env *env, int nb_tetri)
{
	int		i;
	int		j;

	nb_tetri += 48; // ajout de 48 car int0 != char0 (voir table ascii)
	i = -1;
	while (i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
			if (MAP[i][j] == nb_tetri)
				MAP[i][j] = '\0';
	}
}
