/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/03 14:57:36 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>
#include <stdlib.h>

static void		init_env(t_env *env)
{
	ft_bzero(env, sizeof(*env));
}

static void		check_ac_av(t_env *env, int *ac, char **av)
{
	if (*ac != 2)
	{
		ft_putendl_fd("error: you must specify one and only one argument", 2);
		exit(1);
	}
	FILENAME = av[1];
}

int				main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	check_ac_av(&env, &ac, av);
	get_tetriminos(t_env &env);
	return (0);
}
