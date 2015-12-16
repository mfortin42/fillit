/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:31:51 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/16 08:12:29 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int				main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_exit("error");
	ft_bzero(&env, sizeof(env));
	get_tetriminos(&env, av[1]);
	launch_recursive_solver(&env);
	print_solved_map(&env);
	return (0);
}
