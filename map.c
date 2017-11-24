/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:28:45 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 09:19:15 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_chkfill(t_tetr *t, t_map d, char *map)
{
	int			c;

	c = 0;
	while (c < 4)
	{
		if (t->x[c] + d.x < 0 || t->x[c] + d.x >= d.w || t->y[c] + d.y >= d.w)
		{
			return (NULL);
			free(map);
		}
		if (map[(d.x + t->x[c]) + (d.y + t->y[c]) * d.w] != '.')
		{
			free(map);
			return (NULL);
		}
		c++;
	}
	c = 0;
	while (c < 4)
	{
		map[(d.x + t->x[c]) + (d.y + t->y[c]) * d.w] = t->nb + 'A' - 1;
		c++;
	}
	return (map);
}

static char		*ft_recur(t_tetr *t, t_map m_data, char *map)
{
	char		*res;

	res = NULL;
	if (!t)
	{
		res = ft_strdup(map);
		free(map);
		return (res);
	}
	if ((res = ft_chkfill(t, m_data, ft_strdup(map))) > 0)
		res = ft_recur(t->next, md_reset(m_data), res);
	if (1 + m_data.x + m_data.y * m_data.w < m_data.w * m_data.w && !res)
	{
		m_data.x++;
		if (m_data.x >= m_data.w)
		{
			m_data.y++;
			m_data.x %= m_data.w;
		}
		res = ft_recur(t, m_data, ft_strdup(map));
	}
	free(map);
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

static char		*ft_backtrack(t_tetr *t, t_map map_data)
{
	char		*map;
	char		*res;

	res = NULL;
	map = (char *)malloc(map_data.w * map_data.w + 1);
	ft_filldot(&map, map_data.w);
	if (!(res = ft_recur(t, map_data, ft_strdup(map))))
	{
		free(map);
		return (res);
	}
	free(map);
	return (res);
}

char			*ft_map(t_tetr *t, int *s)
{
	int			size;
	t_map		map_data;
	char		*res;

	map_data.x = 0;
	map_data.y = 0;
	res = NULL;
	size = ft_list_size(t);
	map_data.w = ft_nextsqr(size * 4);
	while (!(res = ft_backtrack(t, map_data)))
		map_data.w++;
	*s = map_data.w;
	return (res);
}
