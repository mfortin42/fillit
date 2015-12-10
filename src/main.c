/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/10 08:37:59 by dw31             ###   ########.fr       */
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
		ft_exit("error: you must specify one and only one argument");
	FILENAME = av[1];
}

static void		init_before_recursive(t_env *env)
{
	int		i;

// on fait une copie complete de la structure tetri
// c'est pour ensuite ne faire seulement que des memcpy (evite de remalloc)
// au final ce n'est qu'un copier-coller de la fonction convert_strtab_to_tetri
	if (!(TETRI_SAVED = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * NB_TETRI)))
		ft_exit("malloc error");
	i = -1;
	while (++i < NB_TETRI)
	{
		if (!(TETRI_SAVED[i] = (t_tetri*)ft_memalloc(sizeof(t_tetri)))
		|| !(env->tetri[i]->content = (char**)ft_memalloc(sizeof(char*) * 4))
		|| !(env->tetri[i]->content[0] = ft_strsub(TETRI_STRTAB[i * 4], 0, 4))
		|| !(env->tetri[i]->content[1] = ft_strsub(TETRI_STRTAB[i * 4 + 1], 0, 4))
		|| !(env->tetri[i]->content[2] = ft_strsub(TETRI_STRTAB[i * 4 + 2], 0, 4))
		|| !(env->tetri[i]->content[3] = ft_strsub(TETRI_STRTAB[i * 4 + 3], 0, 4)))
			ft_exit("malloc error");
		env->tetri[i]->x = 0;
		env->tetri[i]->y = 0;
	}
	
// on met une valeur plus grande que ce qui est possible pour etre sur de
// sauvegarder au premier passage
	SIZE_MAP_SAVED = 4242;



// ici il faut malloc la map (MAP_SIZE lignes, MAP_SIZE colonnes) puis faire un bzero dessus

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
