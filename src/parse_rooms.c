/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:08:28 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/10 18:50:33 by nalysann         ###   ########.fr       */
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
		return (0);
	}
	if (words[0][0] == 'L')
		ft_throw(ROOM_NAME_MSG, E_INPUT);
	number = ft_strtoll(words[1], &endptr, 10);
	if (words[1][0] == '\0' || endptr[0] != '\0' ||
		!(INT_MIN <= number && number <= INT_MAX))
		ft_throw(ROOM_COORD_MSG, E_INPUT);
	number = ft_strtoll(words[2], &endptr, 10);
	if (words[2][0] == '\0' || endptr[0] != '\0' ||
		!(INT_MIN <= number && number <= INT_MAX))
		ft_throw(ROOM_COORD_MSG, E_INPUT);
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
	free(words[1]);
	free(words[2]);
	free(words);
}

static int		is_valid_room(t_vector *rooms, char *line, int idx,
								t_room_type type)
{
	t_room	*room_in;
	t_room	*room_out;

	room_in = (t_room *)malloc(sizeof(t_room));
	room_out = (t_room *)malloc(sizeof(t_room));
	if (room_in == NULL || room_out == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	if (!is_room_line(line))
		return (0);
	room_init(room_in, line, 2 * idx, type);
	room_init(room_out, line, 2 * idx + 1, type);
	if (get_room_index_by_name(rooms, room_in->name, 'o') != NO_ROOM)
		ft_throw("Room error", E_INPUT);
	if (ft_strchr(room_in->name, '-'))
		ft_throw("ERROR: Rooms with '-' not valid", E_INPUT);
	vector_push_back(rooms, room_in);
	vector_push_back(rooms, room_out);
	return (1);
}

static void		parse_command(char *line, t_room_type *type, t_dinic *info)
{
	if (ft_strequ(line, C_START))
	{
		if (info->s != NO_ROOM)
			ft_throw(MULT_START_MSG, E_INPUT);
		info->s = 0;
		*type = R_SOURCE;
	}
	else if (ft_strequ(line, C_END))
	{
		if (info->t != NO_ROOM)
			ft_throw(MULT_END_MSG, E_INPUT);
		info->t = 0;
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
		if (line[0] == '#' && line[1] != '#')
			continue;
		list_push_back(input, line);
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
