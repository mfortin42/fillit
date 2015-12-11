/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solved_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/11 23:50:20 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

//- print_solved_map() print the map on stdout (by replacing numbers by letters)

static void		empty_map(t_env *env)
{
	int		i;

	i = -1;
	while (++i < MAP_WIDTH)
		ft_bzero(MAP[i], 5);
}

static void		fill_map(t_env *env)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < NB_TETRI)
		add_tetri_in_map(env, i);
	i = -1;
	c = 'A';
	while (++i < MAP_WIDTH)
	{
		j = -1;
		while (++j < MAP_WIDTH)
			replace_tetri_in_map(env, MAP[i][j], c++);
	}
}

void	print_solved_map(t_env *env)
{
	int		i;
	int		j;

	empty_map(env);
	fill_map(env);
	i = -1;
	while (++i < MAP_WIDTH)
	{
		if (!MAP[i][0] && !MAP[i][1] && !MAP[i][2] && !MAP[i][3])
			break ;
		j = -1;
		while (++j < MAP_WIDTH)
			ft_putchar((MAP[i][j]) ? MAP[i][j] : '.' );
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
