/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solved_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/13 17:28:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		cp_tetrisaved_to_tetri(t_env *env)
{
	int		i;

	i = -1;
	while (++i < NB_TETRI)
	{
		TETRI[i]->x = TETRI_SAVED[i]->x;
		TETRI[i]->y = TETRI_SAVED[i]->y;
		ft_memcpy(TETRI[i]->content[0], TETRI_SAVED[i]->content[0], 5);
		ft_memcpy(TETRI[i]->content[1], TETRI_SAVED[i]->content[1], 5);
		ft_memcpy(TETRI[i]->content[2], TETRI_SAVED[i]->content[2], 5);
		ft_memcpy(TETRI[i]->content[3], TETRI_SAVED[i]->content[3], 5);
	}
	MAP_SIZE = SIZE_MAP_SAVED;
}

static void		empty_map(t_env *env)
{
	int		i;

	i = -1;
	while (++i < MAP_WIDTH)
		ft_bzero(MAP[i], MAP_WIDTH);
}

static void		fill_map(t_env *env)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	c = 'a';
	while (++i < NB_TETRI)
		add_tetri_in_map(env, i);
	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
			if (MAP[i][j])
				MAP[i][j] += 17;
			else
				MAP[i][j] = '.';
		}
	}
}

void			print_solved_map(t_env *env)
{
	int		i;
	int		j;

	cp_tetrisaved_to_tetri(env);
	empty_map(env);
	fill_map(env);
	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
			ft_putchar((MAP[i][j]) ? MAP[i][j] : '.');
		ft_putchar('\n');
	}
}
