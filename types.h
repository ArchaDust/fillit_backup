/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosnet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:50:48 by grosnet-          #+#    #+#             */
/*   Updated: 2017/11/23 09:42:57 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct		s_tetr
{
	char			x[4];
	char			y[4];
	char			nb;
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_map
{
	int				x;
	int				y;
	int				w;
}					t_map;

#endif
