/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 10:12:25 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 10:27:26 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	int		file;
	t_tetr	*first;
	char	*map;
	int		mapsize;

	if (argc != 2)
		usage();
	file = open(argv[1], 'r');
	if (!file || !(first = check_file(file)))
	{
		ft_putstr("error\n");
		exit(FAILURE);
	}
	mapsize = 0;
	map = ft_map(first, &mapsize);
	ft_showit(map, mapsize);
	free(map);
	return (SUCCESS);
}
