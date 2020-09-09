/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:47:21 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/01 13:47:22 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "room.h"
#include "solve.h"

#include "ft_list.h"
#include "ft_math.h"
#include "ft_string.h"
#include "ft_vector.h"

#include <limits.h>

#include "ft_stdio.h"

static void		set_initial_links(t_dinic *info, t_vector *rooms)
{
	size_t	i;

	i = 0;
	while (i < rooms->size)
	{
		info->last[i] = ((t_room *)rooms->data[i])->links.front;
		++i;
	}
}

static int		bfs(t_dinic *info, t_vector *rooms)
{
	t_list	queue;
	int		v;
	t_node	*link;
	t_edge	*e;

	list_init(&queue);
	list_push_back(&queue, (void *)(long long)info->s);
	ft_memset(info->d, NOT_VISITED, info->n * sizeof(info->d[0]));
	info->d[info->s] = 0;
	while (queue.size > 0 && info->d[info->t] == NOT_VISITED)
	{
		v = (int)(long long)list_pop_front(&queue);
		link = ((t_room *)rooms->data[v])->links.front;
		while (link != NULL)
		{
			e = (t_edge *)info->edges.data[(size_t)link->data];
			if (info->d[e->to] == NOT_VISITED && e->flow < e->cap)
			{
				list_push_back(&queue, (void *)(long long)e->to);
				info->d[e->to] = info->d[v] + 1;
			}
			link = link->next;
		}
	}
	return (info->d[info->t] != NOT_VISITED);
}

static int	dfs(t_dinic *info, t_vector *rooms, int v, int flow)
{
	t_edge	*e;
	t_edge	*e_rev;
	int		pushed;

	if (flow == 0)
		return (0);
	if (v == info->t)
		return (flow);
	while (info->last[v] != NULL)
	{
		e = (t_edge *)info->edges.data[(size_t)info->last[v]->data];
		e_rev = (t_edge *)info->edges.data[(size_t)info->last[v]->data ^ 1UL];
		if (info->d[e->to] == info->d[v] + 1)
		{
			pushed = dfs(info, rooms, e->to, ft_min(flow, e->cap - e->flow));
			if (pushed != 0)
			{
				e->flow += pushed;
				e_rev->flow -= pushed;
				return (pushed);
			}
		}
		info->last[v] = info->last[v]->next;
	}
	return (0);
}

t_list	*dinic(t_dinic *info, t_vector *rooms, int number_of_ants)
{
	t_list	*best_paths;
	t_list	*cur_paths;
	double	best_turns;
	double	cur_turns;

	best_paths = NULL;
	best_turns = 0.0;
	while (1)
	{
		if (!bfs(info, rooms))
			break ;
		set_initial_links(info, rooms);
		while (dfs(info, rooms, info->s, INT_MAX))
			;
		cur_paths = get_paths(rooms, info);
		cur_turns = count_turns(cur_paths, number_of_ants);
		if (best_paths == NULL || cur_turns < best_turns)
		{
			best_paths = cur_paths;
			best_turns = cur_turns;
//			TODO: free old paths
		}
	}
	return (best_paths);
}
