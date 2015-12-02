/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/02 23:24:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TETRI_TAB env->tetri_tab
# define TETRI(x) env->tetri_tab[x*4]
# define NB_TETRI env->nb_tetri
# define FILENAME env->filename

typedef struct	s_env
{
	char		**tetri_tab;
	int			nb_tetri;
	char		*filename;
}				t_env;

void			get_tetriminos(t_env *env);

#endif
