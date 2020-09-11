/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:13:12 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:11:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include "ft_list.h"

# include <stddef.h>

# define C_START	"##start"
# define C_END		"##end"

# define NO_ROOM	(-1)
# define EXST_ROOM	(-2)

typedef enum	e_room_type
{
	R_DEFAULT,
	R_SOURCE,
	R_SINK
}				t_room_type;

typedef struct	s_room
{
	t_list			links;
	char			*name;
	int				index;
	t_room_type		type;
	int				x;
	int				y;
}				t_room;

#endif
