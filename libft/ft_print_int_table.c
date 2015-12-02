/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:00:48 by mfortin           #+#    #+#             */
/*   Updated: 2015/11/24 11:07:52 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_table(int *tab, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		i++;
	}
}
