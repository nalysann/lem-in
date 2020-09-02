/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:08:34 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 13:08:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "room.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_vector.h"

#include <stdlib.h>
#include <unistd.h>

static size_t	get_room(t_vector *rooms, char *name, char direction)
{
	size_t	i;
	t_room	*room;

	i = (direction == 'f' ? 1 : 0);
	while (i < rooms->size)
	{
		room = (t_room *)rooms->data[i];
		if (ft_strequ(name, room->name))
			return (room->index);
		i += 2;
	}
	return (NO_ROOM);
}

static void		handle_link(t_vector *rooms, char *line)
{
	char	**words;
	size_t	from;
	size_t	to;

	words = ft_strsplit(line, '-');
	if (count_words(words) != 2)
		ft_throw(LINK_MSG, E_INPUT);
	from = get_room(rooms, words[0], 'f');
	to = get_room(rooms, words[1], 't');
	if (from == NO_ROOM || to == NO_ROOM)
		ft_throw(LINK_MSG, E_INPUT);
	((t_room *)rooms->data[from])->links.push_back(&((t_room *)rooms->data[from])->links, (void *)to);
	((t_room *)rooms->data[to])->links.push_back(&((t_room *)rooms->data[to])->links, (void *)from);
	free(line);
//	TODO: check name correctness ???
//	TODO: check loops, repeating links ???
//	TODO: free split ???
}

void	parse_links(t_list *input, t_vector *rooms, char *line)
{
	while (line != NULL)
	{
		if (line != NULL)
			input->push_back(input, line);
		if (line[0] != '#')
			handle_link(rooms, line);
		get_next_line(STDIN_FILENO, &line);
	}
}
