/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 18:16:40 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "room.h"

# include "ft_vector.h"

# include <stddef.h>

# define NULL_MSG			NULL
# define ALLOC_MSG			"ERROR: memory allocation failed"
# define EMPTY_LINE_MSG		"ERROR: empty lines aren't allowed"
# define NO_ANTS_LINE_MSG	"ERROR: no line specifying number of ants"
# define ANTS_NOT_SPEC_MSG	"ERROR: number of ants is not specified yet"
# define ANTS_INVALID_MSG	"ERROR: number of ants should be a positive int"
# define MULT_ROOMS_N_MSG	"ERROR: multiple rooms with the same name"
# define MULT_ROOMS_C_MSG	"ERROR: multiple rooms with the same coordiantes"
# define ROOM_ELL_MSG		"ERROR: room name can't start with 'L'"
# define ROOM_COORD_MSG		"ERROR: room coordinates should be integers"
# define LINK_SPEC_MSG		"ERROR: invalid link specification"
# define LINK_NO_ROOM_MSG	"ERROR: link should contain only existing rooms"
# define NO_START_MSG		"ERROR: no start room"
# define NO_END_MSG			"ERROR: no end room"
# define MULT_START_MSG		"ERROR: multiple start commands"
# define MULT_END_MSG		"ERROR: multiple end commands"
# define NO_PATHS_MSG		"ERROR: no paths from start room to end room"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2
# define E_NO_PATHS		3

int		count_words(char **words);
int		is_good_room_name(char *name);
int		get_room_index_by_type(t_vector *rooms, t_room_type type, char half);
int		get_room_index_by_name(t_vector *rooms, char *name, char half);
int		get_room_index_by_coordinates(t_vector *rooms, int x, int y, char half);

#endif
