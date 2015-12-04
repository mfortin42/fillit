/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/04 13:25:16 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>

void		get_tetriminos(t_env *env)
{
	TETRI_TAB = NULL;
	NB_TETRI = 0;
	if ((FD = open(FILENAME, O_RDONLY)) == -1)
	{
		ft_putendl_fd("error: can't opening file", 2);
		exit(1);
	}
	VREAD = read(FD, BUFF, BUFF_SIZE);
	if ((close(FD)) == -1)
	{
		ft_putendl_fd("error: can't close file", 2);
		exit(1);
	}
	BUFF[VREAD] = '\0';
	if (((VREAD + 1) % 21) != 0)
	{
		ft_putstr("error");
		exit(1);
	}
	TETRI_TAB = ft_strsplit(BUFF, '\n');
}

void		check_tetriminos(t_env *env)
{
	X = -1;
	while (TETRI_TAB[++X] != NULL)
	{
		Y = -1;
		while (TETRI_TAB[X][++Y] != '\0')
			if (TETRI_TAB[X][Y] != '.' || TETRI_TAB[X][Y] != '#')
			{
				ft_putendl_fd("error: wrong character", 2);
				exit(1);
			}
		if (Y != 4)
		{
			ft_putendl_fd("error: wrong length size", 2);
			exit(1);
		}
	}
	if ((X + 1) % 4 != 0)
	{
		ft_putendl_fd("error: wrong number of lines", 2);
		exit(1);
	}
}
