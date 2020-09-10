/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:48:38 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/10 20:26:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "solve.h"

#include "ft_list.h"
#include "ft_vector.h"

#include <stdlib.h>

static void		free_room(void *data)
{
	t_room	*room;

	room = (t_room *)data;
	list_free(&room->links);
	free(room->name);
}

void			free_path(void *data)
{
	t_list	*path;

	path = (t_list *)data;
	list_free(path);
}

static void		free_dinic(t_dinic *info)
{
	vector_free_deep(&info->edges, free);
	free(info->d);
	free(info->last);
}

int				free_all(t_list *input, t_vector *rooms, t_dinic *info,
							t_list *paths)
{
	list_free_deep(input, free);
	vector_free_deep(rooms, free_room);
	free_dinic(info);
	list_free_deep(paths, free_path);
	free(paths);
	return (0);
}
