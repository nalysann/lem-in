/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:04:42 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:11:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "solve.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_vector.h"

#include <stddef.h>
#include <stdlib.h>

static void		get_vertex(t_dinic *info, t_vector *rooms, int v,
							t_list *cur_path)
{
	t_node	*node;
	t_edge	*edge;

	if (cur_path->size == 0 ||
		(size_t)cur_path->back->data != ((size_t)v ^ 1UL))
	{
		list_push_back(cur_path, (void *)(long long)v);
	}
	if (v == info->t)
	{
		return ;
	}
	node = ((t_room *)rooms->data[v])->links.front;
	while (node != NULL)
	{
		edge = (t_edge *)info->edges.data[(size_t)node->data];
		if (edge->flow > 0)
		{
			get_vertex(info, rooms, edge->to, cur_path);
		}
		node = node->next;
	}
}

t_list			*get_paths(t_vector *rooms, t_dinic *info)
{
	t_list	*paths;
	t_list	*cur_path;
	t_node	*node;
	t_edge	*edge;

	paths = (t_list *)malloc(sizeof(t_list));
	if (paths == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	list_init(paths);
	node = ((t_room *)rooms->data[info->s])->links.front;
	while (node != NULL)
	{
		edge = (t_edge *)info->edges.data[(size_t)node->data];
		if (edge->flow > 0)
		{
			cur_path = (t_list *)malloc(sizeof(t_list));
			if (cur_path == NULL)
				ft_throw(ALLOC_MSG, E_ALLOC);
			list_init(cur_path);
			get_vertex(info, rooms, edge->to, cur_path);
			list_push_back(paths, cur_path);
		}
		node = node->next;
	}
	return (paths);
}

double			count_turns(t_list *paths, int number_of_ants)
{
	t_node	*node;
	t_list	*path;
	double	avg_path_len;
	double	avg_ants_per_path;

	avg_path_len = 0.0;
	node = paths->front;
	while (node != NULL)
	{
		path = (t_list *)node->data;
		avg_path_len += path->size;
		node = node->next;
	}
	avg_path_len /= paths->size;
	avg_ants_per_path = (double)number_of_ants / paths->size;
	return (avg_ants_per_path - 1 + avg_path_len);
}
