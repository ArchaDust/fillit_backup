/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   types.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:29:05 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:09:43 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct		s_tetr
{
	char			x[4];
	char			y[4];
	char			nb;
	char			w;
	char			h;
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_map
{
	char			*res;
	int				w;
}					t_map;

#endif
