/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/03 15:00:57 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TETRI_TAB env->tetri_tab
# define TETRI(x) env->tetri_tab[x*4]
# define NB_TETRI env->nb_tetri
# define FILENAME env->filename
# define FD env->fd
# define VREAD env->vread
# define BUFF env->buff
# define BUFF_SIZE 545

typedef struct	s_env
{
	char		**tetri_tab;
	int			nb_tetri;
	char		*filename;
	int			fd;
	int			vread;
	char		buff[BUFF_SIZE + 1];
}				t_env;

void			get_tetriminos(t_env *env);

#endif
