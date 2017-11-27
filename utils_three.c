/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_three.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 11:16:23 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 09:09:47 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		ft_step(t_map *m)
{
	m->x++;
	if (m->x > m->w)
	{
		m->x = 0;
		m->y++;
	}
}

void		ft_backup(t_tetr *t, t_map *m, int tmp)
{
	int		c;

	c = 0;
	m->x = tmp % m->w;
	m->y = tmp / m->w;
	while (c < 4)
	{
		m->res[tmp + t->x[c] + t->y[c] * m->w] = '.';
		c++;
	}
}
