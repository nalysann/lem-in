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

#include "parser.h"
#include "room.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include <stdlib.h>
#include <unistd.h>

static t_room	*get_room(t_list *rooms, char *name)
{
	t_room	*room;

	while (rooms != NULL)
	{
		room = (t_room *)rooms->content;
		if (ft_strequ(name, room->name))
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

static void		handle_link(t_list *rooms, char *line)
{
	t_list	*tmp;
	char	**words;
	t_room	*room1;
	t_room	*room2;

	words = ft_strsplit(line, '-');
	if (count_words(words) != 2)
		ft_throw(LINK_MSG, E_INPUT);
	room1 = get_room(rooms, words[0]);
	room2 = get_room(rooms, words[1]);
	if (room1 == NULL || room2 == NULL)
		ft_throw(LINK_MSG, E_INPUT);
	tmp = ft_lstnew(room2, sizeof(t_room));
	if (tmp == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ft_lstadd(&room1->neighbors, tmp);
	tmp = ft_lstnew(room1, sizeof(t_room));
	if (tmp == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ft_lstadd(&room2->neighbors, tmp);
	free(line);
}

void	parse_links(t_list *rooms, t_list *input, char *line)
{
	while (line != NULL)
	{
		// ignore comments and commands ??
		if (line[0] != '#')
			handle_link(rooms, line);
		get_next_line(STDIN_FILENO, &line);
		if (line != NULL)
			save_line(&input, line);
	}
}
