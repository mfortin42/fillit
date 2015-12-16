/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/16 08:45:08 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		calc_size_start_value(t_env *env)
{
	int		n;
	float	r;
	float	s;
	int		i;

	n = (NB_TETRI) ? NB_TETRI : 1;
	r = 1;
	i = 0;
	while (++i <= n)
		r = 0.5 * (r + n / r);
	s = r - (int)r;
	return ((s > 0) ? (int)r + 1 : r);
}

static void		init_before_recursive(t_env *env)
{
	int			i;

	if (!(TETRI_SAVED = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * NB_TETRI)))
		ft_exit("error");
	i = -1;
	while (++i < NB_TETRI)
	{
		if (!(TETRI_SAVED[i] = (t_tetri*)ft_memalloc(sizeof(t_tetri)))
		|| !(TETRI_SCONTENT(i) = (char**)ft_memalloc(sizeof(char*) * 4))
		|| !(TETRI_SCONTENT(i)[0] = ft_strsub(TETRI_STRTAB[i * 4], 0, 4))
		|| !(TETRI_SCONTENT(i)[1] = ft_strsub(TETRI_STRTAB[i * 4 + 1], 0, 4))
		|| !(TETRI_SCONTENT(i)[2] = ft_strsub(TETRI_STRTAB[i * 4 + 2], 0, 4))
		|| !(TETRI_SCONTENT(i)[3] = ft_strsub(TETRI_STRTAB[i * 4 + 3], 0, 4)))
			ft_exit("error");
		TETRI_SAVED[i]->x = 0;
		TETRI_SAVED[i]->y = 0;
	}
	MAP = (char**)ft_memalloc(sizeof(char*) * MAP_WIDTH);
	i = -1;
	while (++i < MAP_WIDTH)
		MAP[i] = (char*)ft_strnew(MAP_WIDTH);
	MAP_SIZE = 4242;
	SIZE_MAP_SAVED = 4242;
	MAP_WIDTH = calc_size_start_value(env);
}

static void		recursive_solver(t_env *env, int cur_tetri)
{
	TETRI_Y(cur_tetri) = -1;
	while (SIZE_MAP_SAVED == 4242
	&& ++TETRI_Y(cur_tetri) < MAP_WIDTH)
	{
		TETRI_X(cur_tetri) = -1;
		while (SIZE_MAP_SAVED == 4242
		&& ++TETRI_X(cur_tetri) < MAP_WIDTH)
		{
			if (add_tetri_in_map(env, cur_tetri))
				continue ;
			if (cur_tetri + 1 == NB_TETRI)
			{
				save_map(env);
				return ;
			}
			else
				recursive_solver(env, cur_tetri + 1);
			replace_tetri_in_map(env, cur_tetri, 0);
		}
	}
}

void			launch_recursive_solver(t_env *env)
{
	init_before_recursive(env);
	while (++MAP_WIDTH < MAP_WIDTH_SAVED && SIZE_MAP_SAVED == 4242)
	{
		recursive_solver(env, 0);
	}
}
