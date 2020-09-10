/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/10 19:47:38 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "room.h"

# include "ft_vector.h"

# include <stddef.h>

# define NULL_MSG			NULL
# define ALLOC_MSG			"ERROR: memory allocation failed"
# define NO_ANTS_LINE_MSG	"ERROR: no line specifying number of ants"
# define ANTS_NOT_SPEC_MSG	"ERROR: number of ants is not specified yet"
# define ANTS_INVALID_MSG	"ERROR: number of ants should be a positive integer"
# define ROOM_NAME_MSG		"ERROR: room name can't start with 'L'"
# define ROOM_COORD_MSG		"ERROR: room coordinates aren't valid integers"
# define LINK_MSG			"ERROR: invalid link"
# define NO_START_MSG		"ERROR: no start room"
# define NO_END_MSG			"ERROR: no end room"
# define MULT_START_MSG		"ERROR: multiple start rooms"
# define MULT_END_MSG		"ERROR: multiple end rooms"
# define NO_PATHS_MSG		"ERROR: no paths from start room to end room"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2
# define E_NO_PATHS		3

int		count_words(char **words);
int		get_room_index_by_type(t_vector *rooms, t_room_type type, char half);
int		get_room_index_by_name(t_vector *rooms, char *name, char half);

#endif
