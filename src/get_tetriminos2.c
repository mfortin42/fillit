/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <mfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:28:52 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/13 16:25:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void   check_cur_pos_tetri(t_env *env, int i, int *count)
{
  if (*count < 4 && ((X < 3 && TETRI_CONTENT(i)[Y][X + 1] == '#')
  || (X > 0 && TETRI_CONTENT(i)[Y][X - 1] == '#')
  || (Y < 3 && TETRI_CONTENT(i)[Y + 1][X] == '#')
  || (Y > 0 && TETRI_CONTENT(i)[Y - 1][X] == '#')))
    *count = *count + 1;
  else
    ft_exit("error");
}

void      check_each_tetri_composition(t_env *env)
{
  int   i;
  int   count;

  i = -1;
  count = 0;
  while (++i < NB_TETRI)
  {
    Y = -1;
    while (++Y < 4)
    {
      X = -1;
      while (++X < 4)
        if (TETRI_CONTENT(i)[Y][X] == '#')
          check_cur_pos_tetri(env, i, &count);
    }
  }
}
