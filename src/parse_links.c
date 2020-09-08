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
#include "solve.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_vector.h"

#include <stdlib.h>
#include <unistd.h>

static void		add_edge(t_dinic *info, t_vector *rooms, int from, int to)
{
	t_edge	*e;
	t_edge	*e_rev;

	e = (t_edge *)malloc(sizeof(t_edge));
	e_rev = (t_edge *)malloc(sizeof(t_edge));
	if (e == NULL || e_rev == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	e->from = from;
	e->to = to;
	e->cap = 1;
	e->flow = 0;
	e_rev->from = to;
	e_rev->to = from;
	e_rev->cap = 0;
	e_rev->flow = 0;
	list_push_back(&((t_room *)rooms->data[from])->links, (void *)info->edges.size);
	vector_push_back(&info->edges, e);
	list_push_back(&((t_room *)rooms->data[to])->links, (void *)info->edges.size);
	vector_push_back(&info->edges, e_rev);
}

static void		handle_link(t_vector *rooms, char *line, t_dinic *info)
{
	char	**words;
	int		from;
	int		to;

	words = ft_strsplit(line, '-');
	if (count_words(words) != 2)
		ft_throw(LINK_MSG, E_INPUT);
	from = get_room_index_by_name(rooms, words[0], 'o');
	to = get_room_index_by_name(rooms, words[1], 'i');
	if (from == NO_ROOM || to == NO_ROOM)
		ft_throw(LINK_MSG, E_INPUT);
	add_edge(info, rooms, from, to);
//	TODO: check name correctness ???
//	TODO: check loops, repeating links ???
//	TODO: free split ???
}

static void		add_split_links(t_vector *rooms, t_dinic *info)
{
	int		from;
	int		to;

	from = 0;
	to = 1;
	while (to < (int)rooms->size)
	{
		add_edge(info, rooms, from, to);
		from += 2;
		to += 2;
	}
}

void	parse_links(t_list *input, t_vector *rooms, char *line, t_dinic *info)
{
	while (line != NULL)
	{
		if (line[0] != '#')
			handle_link(rooms, line, info);
		get_next_line(STDIN_FILENO, &line);
		if (line != NULL)
			list_push_back(input, line);
	}
	add_split_links(rooms, info);
}
