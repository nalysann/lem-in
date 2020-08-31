/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:13:12 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/30 19:13:14 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include "ft_list.h"

#include <stddef.h>

# define START	"##start"
# define END	"##end"

typedef enum	e_room_type
{
	R_DEFAULT,
	R_SOURCE,
	R_SINK
}				t_room_type;

typedef struct	s_room
{
	char			*name;
	t_list			*neighbors;
	size_t			index;
	int				x;
	int				y;
	t_room_type		type;
}				t_room;

#endif