/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/08 08:06:14 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static void		check_tetriminos(t_env *env)
{
	X = -1;
	while (TETRI_STRTAB[++X] != NULL)
	{
		Y = -1;
		while (TETRI_STRTAB[X][++Y] != '\0')
			if (TETRI_STRTAB[X][Y] != '.' && TETRI_STRTAB[X][Y] != '#')
				ft_exit("error: wrong character");
		if (Y != 4)
			ft_exit("error: wrong length size");
	}
	if ((X + 1) % 4 != 0)
		ft_exit("error: wrong number of lines");
	NB_TETRI = (X + 1) % 4;
}

static void		convert_strtab_to_tetri(t_env *env)
{
	int		i;

	if (!(env->tetri = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * NB_TETRI)))
		ft_exit("malloc error");
	i = -1;
	while (++i < NB_TETRI)
	{
		if (!(TETRI[i] = (t_tetri*)ft_memalloc(sizeof(t_tetri)))
		|| !(TETRI_CONTENT(i)[0] = ft_strsub(TETRI_STRTAB[i * 4], 0, 4))
		|| !(TETRI_CONTENT(i)[1] = ft_strsub(TETRI_STRTAB[i * 4 + 1], 0, 4))
		|| !(TETRI_CONTENT(i)[2] = ft_strsub(TETRI_STRTAB[i * 4 + 2], 0, 4))
		|| !(TETRI_CONTENT(i)[3] = ft_strsub(TETRI_STRTAB[i * 4 + 3], 0, 4)))
			ft_exit("malloc error");
		TETRI_X(i) = 0;
		TETRI_Y(i) = 0;
	}
}

void			get_tetriminos(t_env *env)
{
	if ((FD = open(FILENAME, O_RDONLY)) == -1)
		ft_exit("error: can't open file");
	if ((VREAD = read(FD, BUFF, BUFF_SIZE)) == -1)
		ft_exit("error: can't read file");
	if ((close(FD)) == -1)
		ft_exit("error: can't close file");
	BUFF[VREAD] = '\0';
	if (((VREAD + 1) % 21) != 0)
		ft_exit("error");
	if ((TETRI_STRTAB = ft_strsplit(BUFF, '\n')) == NULL)
		ft_exit("error");
	check_tetriminos(env);
	convert_strtab_to_tetri(env);
}
