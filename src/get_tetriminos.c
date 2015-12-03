/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/03 16:17:00 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>

void		get_tetriminos(t_env *env)
{
	TETRI_TAB = NULL;
	NB_TETRI = 0;
	FD = open(FILENAME, O_RDONLY);

	if (FD == NULL)
	{
		ft_putendl_fd("error: can't opening file", 2);
		exit(1);
	}
	VREAD = read(FD, BUFF, BUFF_SIZE);
	BUFF[VREAD] = '\0';
	TETRI_TAB = ft_strsplit(BUFF, '\n');
}

void		check_tetriminos(t_env *env)
{
	X = 0;

	while (TETRI_TAB[X] != NULL)
	{
		Y = 0;
		while (TETRI_TAB[X][Y] != '\0')
		{
			Y++;
		}
		X++;
	}
}
