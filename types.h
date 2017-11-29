/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   types.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:29:05 by aberneli     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2017/11/29 11:09:43 by aberneli    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2017/11/28 16:12:16 by aberneli    ###    #+. /#+    ###.fr     */
>>>>>>> a54ec7e58c933b0872b6cfdc4ba4f3984ddc2104
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct		s_tetr
{
	char			x[4];
	char			y[4];
<<<<<<< HEAD
	char			nb;
	char			w;
	char			h;
=======
	int				nb;
>>>>>>> a54ec7e58c933b0872b6cfdc4ba4f3984ddc2104
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_map
{
	char			*res;
	int				w;
}					t_map;

#endif
