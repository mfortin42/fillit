/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/13 16:25:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		search_first_sharp(t_env *env, int i)
{
	Y = -1;
	while (++Y < 4)
	{
		X = -1;
		while (++X < 4)
			if (TETRI_CONTENT(i)[Y][X] == '#')
				return ;
	}
}

static void		assign_last_x_y(int x, int y, int *last_x, int *last_y)
{
	*last_y = y;
	*last_x = x;
}

static void		check_1tetri_compo(t_env *env, int i, int count, int must_exit)
{
	int		last_x;
	int		last_y;

	assign_last_x_y(-1, -1, &last_x, &last_y);
	while (count < 4)
	{
		if ((X + 1 != last_x || Y != last_y) && X >= 0 && Y >= 0 && X + 1 < 4
		&& Y < 4 && TETRI_CONTENT(i)[Y][X + 1] == '#')
			assign_last_x_y(X++, Y, &last_x, &last_y);
		else if ((X - 1 != last_x || Y != last_y) && X - 1 >= 0 && Y >= 0 && X < 4
		&& Y < 4 && TETRI_CONTENT(i)[Y][X - 1] == '#')
			assign_last_x_y(X--, Y, &last_x, &last_y);
		else if ((X != last_x || Y + 1 != last_y) && X >= 0 && Y >= 0 && X < 4
		&& Y + 1 < 4 && TETRI_CONTENT(i)[Y + 1][X] == '#')
			assign_last_x_y(X, Y++, &last_x, &last_y);
		else if ((X != last_x || Y - 1 != last_y) && X >= 0 && Y - 1 >= 0 && X < 4
		&& Y < 4 && TETRI_CONTENT(i)[Y - 1][X] == '#')
			assign_last_x_y(X, Y--, &last_x, &last_y);
		else if (must_exit)
			ft_exit("error");
		else if (!must_exit)
			return ;
		count++;
	}
}

void			check_each_tetri_composition(t_env *env)
{
	int		i;

	X = 0;
	Y = 0;
	i = -1;
	while (++i < NB_TETRI)
	{
		search_first_sharp(env, i);
		check_1tetri_compo(env, i, 0, 0);
		check_1tetri_compo(env, i, 0, 1);
	}
}
