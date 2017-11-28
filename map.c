/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:28:45 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:14:19 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_chkfill(t_tetr *t, t_map *d)
{
	int			tmp;
	int			c;

	tmp = d->x + d->y * d->w;
	c = 0;
	while (c < 4)
	{
		if (t->x[c] + d->x < 0 || t->x[c] + d->x >= d->w)
			return (0);
		if (t->y[c] + d->y >= d->w)
			return (0);
		if (d->res[tmp + t->x[c] + t->y[c] * d->w] != '.')
			return (0);
		c++;
	}
	c = 0;
	while (c < 4)
	{
		d->res[tmp + t->x[c] + t->y[c] * d->w] = (char)t->nb;
		c++;
	}
	return (1);
}

static int		ft_recur(t_tetr *t, t_map *m_data)
{
	int			res;
	int			tmp;

	tmp = 0;
	res = 0;
	if (!t)
		return (1);
	if ((ft_chkfill(t, m_data)))
	{
		tmp = m_data->x + m_data->y * m_data->w;
		m_data->x = 0;
		m_data->y = 0;
		if (!(res = ft_recur(t->next, m_data)))
			ft_backup(t, m_data, tmp);
	}
	if (1 + m_data->x + m_data->y * m_data->w < m_data->w * m_data->w && !res)
	{
		ft_step(m_data);
		res = ft_recur(t, m_data);
	}
	return (res);
}

static void		ft_filldot(char **s, int w)
{
	int			i;

	i = 0;
	while (i < w * w)
	{
		s[0][i] = '.';
		i++;
	}
	s[0][i] = '\0';
}

static int		ft_backtrack(t_tetr *t, t_map *map_data)
{
	if (!(ft_recur(t, map_data)))
		return (0);
	return (1);
}

char			*ft_map(t_tetr *t, int *s)
{
	t_map		*map_data;
	char		*res;

	map_data = (t_map *)malloc(sizeof(t_map));
	map_data->x = 0;
	map_data->y = 0;
	map_data->w = ft_nextsqr(ft_list_size(t) * 4);
	map_data->res = (char *)malloc(map_data->w * map_data->w + 1);
	ft_filldot(&map_data->res, map_data->w);
	while (!(ft_backtrack(t, map_data)))
	{
		map_data->w++;
		map_data->x = 0;
		map_data->y = 0;
		free(map_data->res);
		map_data->res = (char *)malloc(map_data->w * map_data->w + 1);
		ft_filldot(&map_data->res, map_data->w);
	}
	*s = map_data->w;
	res = map_data->res;
	free(map_data);
	return (res);
}
