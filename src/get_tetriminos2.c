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

// j'ai fait une autre fonction pour passer les 25lignes de la norme...
static void		check_one_tetri_composition(t_env *env, int i, int x, int y)
{
	int		count;

	count = 0;
	search_first_sharp(env, i, &x, &y);
	while (count < 4)
	{
		if (x >= 0 && y >= 0 && x + 1 < 4
		&& y < 4 && TETRI_CONTENT(i)[y][x + 1] == '#')
			x++;
		else if (x - 1 >= 0 && y >= 0 && x < 4
		&& y < 4 && TETRI_CONTENT(i)[y][x - 1] == '#')
			x--;
		else if (x >= 0 && y >= 0 && x < 4
		&& y + 1 < 4 && TETRI_CONTENT(i)[y + 1][x] == '#')
			y++;
		else if (x >= 0 && y -1 >= 0 && x < 4
		&& y < 4 && TETRI_CONTENT(i)[y - 1][x] == '#')
			y--;
		else
			ft_exit("error: somes # aren't nears");
		count++; // inutile de le faire pour chaque cas plus haut, si on est la c'est qu'on a bien trouve un # (sinon ca aurait exit)
	}
}

void			check_each_tetri_composition(t_env *env)
{
	int		i;
	int		x;
	int		y;

// pour chaque tetri:
	// on cherche le premier #
	// puis on cherche dans ses cases adjacentes s'il y a un #
	// soit x-1 x+1 y-1 y+1 (avec verif qu'on soit pas <0 ni >3)
	i = -1;
	x = 0;
	y = 0;
	while (++i < NB_TETRI)
		check_one_tetri_composition(env, i, x, y);
}
