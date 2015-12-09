/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/09 08:38:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		search_first_sharp(t_env *env, int i, int *x, int *y)
{
	// on cherche la position du premier # dans le tetri i
	// on recoit en parametre l'adresse de x/y pour pouvoir ecrire directement dedans
	// des qu'on le trouve on peut return, x/y sont deja sur la bonne position
	*y = 0;
	while (++(*y) < 4)
	{
		*x = 0;
		while (++(*x) < 4)
			if (TETRI_CONTENT(i)[*y][*x] == '#')
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
		if ((X != last_x || Y != last_y) && X >= 0 && Y >= 0 && X + 1 < 4
		&& Y < 4 && TETRI_CONTENT(i)[Y][X + 1] == '#')
			assign_last_x_y(X++, Y, &last_x, &last_y);
		else if ((X != last_x || Y != last_y) && X - 1 >= 0 && Y >= 0 && X < 4
		&& Y < 4 && TETRI_CONTENT(i)[Y][X - 1] == '#')
			assign_last_x_y(X--, Y, &last_x, &last_y);
		else if ((X != last_x || Y != last_y) && X >= 0 && Y >= 0 && X < 4
		&& Y + 1 < 4 && TETRI_CONTENT(i)[Y + 1][X] == '#')
			assign_last_x_y(X, Y++, &last_x, &last_y);
		else if ((X != last_x || Y != last_y) && X >= 0 && Y - 1 >= 0 && X < 4
		&& Y < 4 && TETRI_CONTENT(i)[Y - 1][X] == '#')
			assign_last_x_y(X, Y--, &last_x, &last_y);
		else if (must_exit)
			ft_exit("error: somes # aren't nears");
		else if (!must_exit)
			return ;
		count++;
	}
}

void			check_each_tetri_composition(t_env *env)
{
	int		i;

// pour chaque tetri:
	// on cherche le premier #
	// on le remonte dans un sens pour etre sur d'etre a l'extremite
	// puis on peut commencer le check en cherchant dans ses cases adjacentes s'il y a un #
	// soit x-1 x+1 y-1 y+1 (avec verif qu'on soit pas <0 ni >3)
	X = 0;
	Y = 0;
	i = -1;
	while (++i < NB_TETRI)
	{
	  // on se position sur le premier '#' trouve
		search_first_sharp(env, i, &X, &Y);
	// on remonte jusqu'a l'extremite (on pouvait etre en plein milieu)
		check_1tetri_compo(env, i, 0, 0);
	// on le remonte dans l'autre sens en quittant si erreur (le param 1 ou 0 definit si cette verif est active)
		check_1tetri_compo(env, i, 0, 1);
	}
}
