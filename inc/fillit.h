/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/13 16:30:23 by wide-aze         ###   ########.fr       */
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
# define MAP_WIDTH (NB_TETRI * 4)
# define MAP env->map
# define MAP_SIZE env->size_map
# define TETRI env->tetri
# define TETRI_CONTENT(i) env->tetri[i]->content
# define TETRI_X(i) env->tetri[i]->x
# define TETRI_Y(i) env->tetri[i]->y
# define TETRI_XS(i) env->tetri[i]->x_start
# define TETRI_YS(i) env->tetri[i]->y_start
# define TETRI_SAVED env->tetri_saved
# define TETRI_SCONTENT(i) env->tetri_saved[i]->content
# define SIZE_MAP_SAVED env->size_map_saved

typedef struct		s_tetri
{
	char			**content;
	int				x;
	int				y;
	int				x_start;
	int				y_start;
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
	int				size_map;
	int				size_map_saved;
	int				map_width;
	t_tetri			**tetri;
	t_tetri			**tetri_saved;
}					t_env;

void				check_each_tetri_composition(t_env *env);
void				get_tetriminos(t_env *env);
void				replace_tetri_in_map(t_env *env, int nb_tetri, char c);
void				del_tetri_in_map(t_env *env, int nb_tetri);
int					add_tetri_in_map(t_env *env, int nb_tetri);
void				save_map(t_env *env);
void				recursive_solver(t_env *env, int cur_tetri);
void				print_solved_map(t_env *env);

#endif
