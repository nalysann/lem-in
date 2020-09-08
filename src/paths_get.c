/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:04:42 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/08 14:04:43 by nalysann         ###   ########.fr       */
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

t_list	*get_paths(t_vector *rooms, t_dinic *info)
{
	t_list	*paths;
	t_list	cur_path;

	paths = (t_list *)malloc(sizeof(t_list));
	if (paths == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	list_init(paths);

}

double	count_turns(t_list *paths, int number_of_ants)
{
	t_node	*node;
	t_path	*path;
	double	avg_path_len;
	double	avg_ants_per_path;

	avg_path_len = 0.0;
	node = paths->front;
	while (node != NULL)
	{
		path = (t_path *)node->data;
		avg_path_len += path->rooms.size;
		node = node->next;
	}
	avg_path_len /= paths->size;
	avg_ants_per_path = (double)number_of_ants / paths->size;
	return ((avg_ants_per_path - 1 + avg_path_len) * paths->size);
}
