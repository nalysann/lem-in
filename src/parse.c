/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:31:58 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:11:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "solve.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_vector.h"

#include <stdlib.h>

static void		info_init(t_dinic *info, t_vector *rooms)
{
	vector_init(&info->edges);
	info->n = rooms->size;
	info->s = get_room_index_by_type(rooms, R_SOURCE, 'o');
	if (info->s == NO_ROOM)
	{
		ft_throw(NO_START_MSG, E_INPUT);
	}
	info->t = get_room_index_by_type(rooms, R_SINK, 'i');
	if (info->t == NO_ROOM)
	{
		ft_throw(NO_END_MSG, E_INPUT);
	}
	info->d = (int *)malloc(info->n * sizeof(int));
	info->last = (t_node **)malloc(info->n * sizeof(t_node *));
	if (info->d == NULL || info->last == NULL)
	{
		ft_throw(ALLOC_MSG, E_ALLOC);
	}
}

void			parse(t_list *input, int *number_of_ants, t_vector *rooms,
						t_dinic *info)
{
	char	*line;

	parse_ants(input, number_of_ants);
	info->s = NO_ROOM;
	info->t = NO_ROOM;
	line = parse_rooms(input, rooms, info);
	info_init(info, rooms);
	parse_links(input, rooms, line, info);
}
