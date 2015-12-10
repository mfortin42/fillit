/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/10 07:59:26 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	recursive_solver(t_env *env, int cur_tetri)
{
	TETRI_Y(cur_tetri) = -1;
	while (++TETRI_Y(cur_tetri) < MAP_WIDTH)
	{
		TETRI_X(cur_tetri) = -1;
		while (++TETRI_X(cur_tetri) < MAP_WIDTH)
		{
// pour chaque position (donc a chaque tour de boucle)
// on place le tetri dans la map (si pas possible, on passe a la position suivante)
			if (add_tetri_in_map(env, cur_tetri))
				continue ;
// si c'est le dernier c'est que la map est valide (au final la map est verifiee au fur et a mesure)
// donc si on est sur le dernier on compare si on a une map plus petite que celle deja trouvee
			if (cur_tetri + 1 == NB_TETRI)
			{
				if (MAP_SIZE < SIZE_MAP_SAVED)
					save_map(env);
			}
			else
				recursive_solver(env, cur_tetri + 1);
// si c'est pas le dernier on place les tetris suivants

// on enleve le tetri de la map (pour le placer a la position suivante au prochain tour de boucle)
			del_tetri_in_map(env, cur_tetri);
		}
	}
}
