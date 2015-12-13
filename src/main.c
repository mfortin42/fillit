/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/13 16:23:41 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		init_env(t_env *env)
{
	ft_bzero(env, sizeof(*env));
}

static void		check_ac_av(t_env *env, int *ac, char **av)
{
	if (*ac != 2)
		ft_exit("error");
	FILENAME = av[1];
}

static void		init_before_recursive(t_env *env)
{
	int			i;

	if (!(TETRI_SAVED = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * NB_TETRI)))
		ft_exit("error");
	i = -1;
	while (++i < NB_TETRI)
	{
		if (!(TETRI_SAVED[i] = (t_tetri*)ft_memalloc(sizeof(t_tetri)))
		|| !(TETRI_SCONTENT(i) = (char**)ft_memalloc(sizeof(char*) * 4))
		|| !(TETRI_SCONTENT(i)[0] = ft_strsub(TETRI_STRTAB[i * 4], 0, 4))
		|| !(TETRI_SCONTENT(i)[1] = ft_strsub(TETRI_STRTAB[i * 4 + 1], 0, 4))
		|| !(TETRI_SCONTENT(i)[2] = ft_strsub(TETRI_STRTAB[i * 4 + 2], 0, 4))
		|| !(TETRI_SCONTENT(i)[3] = ft_strsub(TETRI_STRTAB[i * 4 + 3], 0, 4)))
			ft_exit("error");
		TETRI_SAVED[i]->x = 0;
		TETRI_SAVED[i]->y = 0;
	}
	MAP = (char**)ft_memalloc(sizeof(char*) * MAP_WIDTH);
	i = -1;
	while (++i < MAP_WIDTH)
		MAP[i] = (char*)ft_strnew(MAP_WIDTH);
	MAP_SIZE = 4242;
	SIZE_MAP_SAVED = 4242;
}

int				main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	check_ac_av(&env, &ac, av);
	get_tetriminos(&env);
	init_before_recursive(&env);
	recursive_solver(&env, 0);
	print_solved_map(&env);
	return (0);
}
