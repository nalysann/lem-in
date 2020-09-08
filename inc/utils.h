/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 11:39:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "room.h"

#include "ft_vector.h"

# include <stddef.h>

# define NULL_MSG		NULL
# define ERROR_MSG		"ERROR: unknown error"
# define ALLOC_MSG		"ERROR: memory allocation failed"
# define LINE_MSG		"ERROR: invalid line"
# define ANT_MSG		"ERROR: invalid number of ants"
# define ROOM_MSG		"ERROR: invalid room"
# define LINK_MSG		"ERROR: invalid link"
# define START_MSG		"ERROR: next line after ##start must be a valid room"
# define STOP_MSG		"ERROR: next line after ##stop must be a valid room"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2

int		count_words(char **words);
int		get_room_index_by_type(t_vector *rooms, t_room_type type, char half);
int		get_room_index_by_name(t_vector *rooms, char *name, char half);

#endif
