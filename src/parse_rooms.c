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

#include "parser.h"
#include "room.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static bool		is_valid_room(t_list **rooms, char *line)
{
	t_list	*tmp;
	t_room	*room;
	char	**words;

	room = (*rooms)->content;
	words = ft_strsplit(line, ' ');
	if (count_words(words) != 3)
	{
		free(room);
		tmp = *rooms;
		*rooms = (*rooms)->next;
		free(tmp);
		return (false);
	}
	room->x = ft_atoi(words[1]);
	room->y = ft_atoi(words[2]);
	return (true);
}

static void		handle_room(t_list **rooms, char *line, size_t index, t_room_type type)
{
	t_list	*room;
	t_room	*content;

	if (line[0] == 'L')
		ft_throw(ROOM_MSG, E_INPUT);
	room = ft_lstnew(NULL, 0);
	if (room == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ft_lstadd(rooms, room);
	room->content = (t_room *)malloc(sizeof(t_room));
	if (room->content == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	content = (t_room *)room->content;
	content->name = line;
	content->neighbors = NULL;
	content->index = index;
	content->type = type;
}

static void		parse_command(char *line, t_room_type *type)
{
	if (ft_strequ(line, START))
		*type = R_SOURCE;
	else if (ft_strequ(line, END))
		*type = R_SINK;
}

size_t			parse_rooms(t_list **rooms, t_list *input)
{
	char			*line;
	size_t			index;
	t_room_type		type;

	index = 1;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		type = R_DEFAULT;
		save_line(&input, line);
		if (line[0] == '#')
		{
			if (line[1] == '#')
				parse_command(line, &type);
			// else ignore comment
		}
		else
		{
			handle_room(rooms, line, (type == R_SOURCE ? 0 : index), type);
			if (!is_valid_room(rooms, line))
				break ;
		}
		++index;
	}
	parse_links(*rooms, input, line);
//	((t_room *)end_room->content)->index = index + 1;
	return (index + 2);
}
