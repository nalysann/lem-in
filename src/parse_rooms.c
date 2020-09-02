/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:08:28 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 13:08:29 by nalysann         ###   ########.fr       */
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
#include "ft_vector.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static bool		is_room_line(char *line)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	if (count_words(words) != 3)
	{
		return (false);
	}
	if (words[0][0] == 'L')
		ft_throw(ROOM_MSG, E_INPUT);
	return (true);
//	TODO: check name uniqueness
//	TODO: check room coordinates
//	TODO: free split
}

static void		room_init(t_room *room, char *line, size_t idx, t_room_type type)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	room->name = words[0];
	vector_init(&room->links);
	room->x = ft_atoi(words[1]);
	room->y = ft_atoi(words[2]);
	room->index = idx;
	room->type = type;
//	TODO: free split
}

static bool		is_valid_room(t_vector *rooms, char *line, size_t idx, t_room_type type)
{
	t_room	*room_in;
	t_room	*room_out;

	room_in = (t_room *)malloc(sizeof(t_room));
	room_out = (t_room *)malloc(sizeof(t_room));
	if (room_in == NULL || room_out == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	if (!is_room_line(line))
		return (false);
	room_init(room_in, line, 2 * idx, type);
	room_init(room_out, line, 2 * idx + 1, type);
	rooms->push_back(rooms, room_in);
	rooms->push_back(rooms, room_out);
	return (true);
}

static void		parse_command(char *line, t_room_type *type)
{
	if (ft_strequ(line, C_START))
		*type = R_SOURCE;
	else if (ft_strequ(line, C_END))
		*type = R_SINK;
}

char			*parse_rooms(t_list *input, t_vector *rooms)
{
	char			*line;
	size_t			idx;
	t_room_type		type;

	idx = 0;
	type = R_DEFAULT;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		input->push_back(input, line);
		if (line[0] == '#')
		{
			if (line[1] == '#')
				parse_command(line, &type);
			continue ;
		}
		if (!is_valid_room(rooms, line, idx, type))
		{
			input->pop_back(input);
			break ;
		}
		type = R_DEFAULT;
		++idx;
	}
	return (line);
}
