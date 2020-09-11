/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:08:28 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:33:02 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "room.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int		is_room_line(char *line)
{
	char		**words;
	long long	number;
	char		*endptr;

	words = ft_strsplit(line, ' ');
	if (count_words(words) != 3)
	{
		free_split(words, 0);
		return (0);
	}
	number = ft_strtoll(words[1], &endptr, 10);
	if (words[1][0] == '\0' || endptr[0] != '\0' ||
		!(INT_MIN <= number && number <= INT_MAX))
		ft_throw(ROOM_COORD_MSG, E_INPUT);
	number = ft_strtoll(words[2], &endptr, 10);
	if (words[2][0] == '\0' || endptr[0] != '\0' ||
		!(INT_MIN <= number && number <= INT_MAX))
		ft_throw(ROOM_COORD_MSG, E_INPUT);
	free_split(words, 0);
	return (1);
}

static void		room_init(t_room *room, char *line, size_t idx,
							t_room_type type)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	room->name = words[0];
	room->x = ft_atoi(words[1]);
	room->y = ft_atoi(words[2]);
	room->index = idx;
	room->type = type;
	list_init(&room->links);
	free_split(words, 1);
}

static int		is_valid_room(t_vector *rooms, char *line, int idx,
								t_room_type type)
{
	t_room	*room_in;
	t_room	*room_out;

	if (!is_room_line(line))
		return (0);
	room_in = (t_room *)malloc(sizeof(t_room));
	room_out = (t_room *)malloc(sizeof(t_room));
	if (room_in == NULL || room_out == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	room_init(room_in, line, 2 * idx, type);
	room_init(room_out, line, 2 * idx + 1, type);
	if (get_room_index_by_name(rooms, room_in->name, 'i') != NO_ROOM)
		ft_throw(MULT_ROOMS_N_MSG, E_INPUT);
	if (get_room_index_by_coordinates(rooms, room_in->x, room_in->y, 'i') !=
																		NO_ROOM)
		ft_throw(MULT_ROOMS_C_MSG, E_INPUT);
	if (room_in->name[0] == 'L')
		ft_throw(ROOM_ELL_MSG, E_INPUT);
	if (!is_good_room_name(room_in->name))
		ft_throw("ERROR: room name can only contain printable "
				"characters, except ' ' (space), '-' (dash)", E_INPUT);
	vector_push_back(rooms, room_in);
	vector_push_back(rooms, room_out);
	return (1);
}

static void		parse_command(char *line, t_room_type *type, t_dinic *info)
{
	if (ft_strequ(line, C_START))
	{
		if (*type == R_SOURCE || *type == R_SINK)
			ft_throw("ERROR: next non-comment line after "
					"##start or ##end should specify a room", E_INPUT);
		if (info->s != NO_ROOM)
			ft_throw(MULT_START_MSG, E_INPUT);
		info->s = EXST_ROOM;
		*type = R_SOURCE;
	}
	else if (ft_strequ(line, C_END))
	{
		if (*type == R_SOURCE || *type == R_SINK)
			ft_throw("ERROR: next non-comment line after "
					"##start or ##end should specify a room", E_INPUT);
		if (info->t != NO_ROOM)
			ft_throw(MULT_END_MSG, E_INPUT);
		info->t = EXST_ROOM;
		*type = R_SINK;
	}
}

char			*parse_rooms(t_list *input, t_vector *rooms, t_dinic *info)
{
	char			*line;
	int				idx;
	t_room_type		type;

	idx = 0;
	type = R_DEFAULT;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (line[0] == '\0')
			ft_throw(EMPTY_LINE_MSG, E_INPUT);
		list_push_back(input, line);
		if (line[0] == '#' && line[1] != '#')
			continue ;
		if (line[0] == '#' && line[1] == '#')
		{
			parse_command(line, &type, info);
			continue ;
		}
		if (!is_valid_room(rooms, line, idx, type))
			break ;
		type = R_DEFAULT;
		++idx;
	}
	return (line);
}
