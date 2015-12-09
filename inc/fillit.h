/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/09 08:15:05 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TETRI_STRTAB env->tetri_tab
# define NB_TETRI env->nb_tetri
# define FILENAME env->filename
# define FD env->fd
# define VREAD env->vread
# define BUFF env->buff
# define BUFF_SIZE 545
# define X env->x
# define Y env->y
# define MAP env->map
# define MAP_SIZE env->map_size
# define TETRI env->tetri
# define TETRI_CONTENT(i) env->tetri[i]->content
# define TETRI_X(i) env->tetri[i]->x
# define TETRI_Y(i) env->tetri[i]->y

typedef struct		s_tetri
{
	char			**content;
	int				x;
	int				y;
}					t_tetri;

typedef struct		s_env
{
	char			**tetri_tab;
	int				nb_tetri;
	char			*filename;
	int				fd;
	int				vread;
	char			buff[BUFF_SIZE + 1];
	int				x;
	int				y;
	char			**map;
	int				map_size;
	t_tetri			**tetri;
}					t_env;

void			get_tetriminos(t_env *env);
void			del_tetri_in_map(t_env *env, int nb_tetri);
void			check_each_tetri_composition(t_env *env);


#endif
