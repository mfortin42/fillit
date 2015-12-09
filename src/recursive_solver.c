/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/09 21:57:52 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	recursive_solver(t_env *env, int cur_tetri)
{
	TETRI_Y(cur_tetri) = -1;
	while (++TETRI_Y(cur_tetri) < MAP_SIZE)
	{
		TETRI_X(cur_tetri) = -1;
		while (++TETRI_X(cur_tetri) < MAP_SIZE)
		{
			if (cur_tetri + 1 == NB_TETRI)
				; // on est le dernier tetri
			else
				recursive_solver(env, cur_tetri + 1);
		}
	}
}
