/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosnet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:09:52 by grosnet-          #+#    #+#             */
/*   Updated: 2017/11/22 11:16:35 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_chkfill(t_tetr *t, t_map d, char *map)
{
	int			c;

	c = 0;
	while (c < 4)
	{
		if (t->x[c] + d.x < 0 || t->x[c] + d.x >= d.w || t->y[c] + d.y >= d.w)
			return (0);
		if (map[(d.x + t->x[c]) + (d.y + t->y[c]) * d.w] != '.')
			return (0);
		c++;
	}
	c = 0;
	while (c < 4)
	{
		map[(d.x + t->x[c]) + (d.y + t->y[c]) * d.w] = t->nb;
		c++;
	}
	return (1);
}

static int		ft_recur(t_tetr *t, t_map m_data, char *map)
{
	int			res;

	res = 0;
	if (!t)
	{
		m_data.res[0] = ft_strdup(map);
		free(map);
		return (1);
	}
	if (ft_chkfill(t, m_data, map))
	{
		m_data.x = 0;
		m_data.y = 0;
		res = ft_recur(t->next, m_data, ft_strdup(map));
	}
	if (2 + m_data.x + m_data.y * m_data.w < m_data.w * m_data.w && !res)
	{
		m_data.x++;
		if (m_data.x >= m_data.w)
			m_data.y++;
		m_data.x %= m_data.w;
		res = ft_recur(t, m_data, ft_strdup(map));
	}
	free(map);
	return (res);
}

static void		ft_filldot(char *s, int w)
{
	int			i;

	i = 0;
	while (i < w * w)
	{
		s[i] = '.';
		i++;
	}
	s[i] = '\0';
}

static int		ft_backtrack(t_tetr *t, t_map map_data)
{
	char		*map;

	map = malloc(map_data.w * map_data.w + 1);
	ft_filldot(map, map_data.w);
	if (!ft_recur(t, map_data, ft_strdup(map)))
	{
		free(map);
		return (0);
	}
	free(map);
	return (1);
}

char			*ft_map(t_tetr *t, int *s)
{
	int			size;
	t_map		map_data;

	map_data.x = 0;
	map_data.y = 0;
	size = ft_list_size(t);
	if (size < 3)
		map_data.w = size + 1;
	else
		map_data.w = ft_nextsqr(size);
	while (!ft_backtrack(t, map_data))
		map_data.w++;
	*s = map_data.w;
	return (map_data.res[0]);
}
