/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_clear.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:50:29 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 08:52:03 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		lst_clear(t_tetr *lst)
{
	t_tetr	*tmp;

	tmp = lst;
	while (tmp)
	{
		lst = tmp->next;
		free(tmp);
		tmp = lst;
	}
}
