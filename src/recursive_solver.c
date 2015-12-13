/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/13 13:16:14 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	recursive_solver(t_env *env, int cur_tetri)
{
	TETRI_Y(cur_tetri) = -1;
	while (++TETRI_Y(cur_tetri) < MAP_WIDTH
	&& TETRI_Y(cur_tetri) < SIZE_MAP_SAVED)
	{
		TETRI_X(cur_tetri) = -1;
		while (++TETRI_X(cur_tetri) < MAP_WIDTH
		&& TETRI_X(cur_tetri) < SIZE_MAP_SAVED)
		{
			if (add_tetri_in_map(env, cur_tetri))
				continue ;
			if (cur_tetri + 1 == NB_TETRI)
			{
				if (MAP_SIZE < SIZE_MAP_SAVED)
					save_map(env);
			}
			else
				recursive_solver(env, cur_tetri + 1);
			replace_tetri_in_map(env, cur_tetri, 0);
		}
	}
}
