/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:48:38 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/10 18:36:58 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "solve.h"

#include "ft_list.h"
#include "ft_vector.h"

#include <stddef.h>
#include <stdlib.h>

static void		free_room(void *data)
{
	t_room	*room;

	room = (t_room *)data;
	list_free(&room->links);
	free(room->name);
}

void			free_paths(t_list *paths)
{
	t_node	*node;
	t_node	*path_node;
	t_node	*tmp;
	t_node	*path_tmp;

	if (paths == NULL)
	{
		return ;
	}
	node = paths->front;
	while (node != NULL)
	{
		tmp = node;
		path_node = ((t_list *)node->data)->front;
		while (path_node != NULL)
		{
			path_tmp = path_node;
			path_node = path_node->next;
			free(path_tmp);
		}
		node = node->next;
		free(tmp->data);
		free(tmp);
	}
	free(paths);
}

static void		free_dinic(t_dinic *info)
{
	vector_free(&info->edges);
	free(info->d);
	free(info->last);
}

int				free_all(t_list *input, t_vector *rooms, t_dinic *info,
							t_list *paths)
{
	list_free(input);
	vector_free_deep(rooms, free_room);
	free_dinic(info);
	free_paths(paths);
	return (0);
}
