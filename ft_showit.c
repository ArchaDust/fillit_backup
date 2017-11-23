/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:05:35 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/23 10:56:13 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_showit(char *map, int mapsize)
{
	int		i;

	i = 0;
	while (i < mapsize * mapsize)
	{
		if (i % mapsize == 0 && i > 0)
			write(1, "\n", 1);
		write(1, &map[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
