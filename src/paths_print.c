/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:04:54 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:06:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "room.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_vector.h"

#include <stddef.h>
#include <stdlib.h>

static void		place_ants_on_paths_internal(t_list *paths, t_pp *pp,
											int *cur_path, t_node **node)
{
	if (*cur_path > 0 &&
		((t_list *)(*node)->data)->size + pp->ants_on_path[*cur_path] >=
		((t_list *)(*node)->prev->data)->size + pp->ants_on_path[*cur_path - 1])
	{
		*cur_path = 0;
		*node = paths->front;
	}
}

static void		place_ants_on_paths(t_list *paths, int number_of_ants, t_pp *pp)
{
	int		cur_ant;
	int		cur_path;
	t_node	*node;

	cur_ant = 0;
	cur_path = 0;
	node = paths->front;
	while (cur_ant < number_of_ants)
	{
		while (node != NULL && node->next != NULL)
		{
			if (((t_list *)node->data)->size + pp->ants_on_path[cur_path] <=
			((t_list *)node->next->data)->size + pp->ants_on_path[cur_path + 1])
				break ;
			++cur_path;
			node = node->next;
		}
		place_ants_on_paths_internal(paths, pp, &cur_path, &node);
		pp->ant_pos[cur_ant] = ((t_list *)node->data)->front;
		pp->ant_wait[cur_ant] = pp->ants_on_path[cur_path]++;
		++cur_ant;
	}
}

static void		move_ants_internal(t_vector *rooms, t_pp *pp, int cur_ant,
									int *printed)
{
	int		room_index;

	if (pp->ant_wait[cur_ant] != 0)
		--pp->ant_wait[cur_ant];
	else if (pp->ant_pos[cur_ant] != NULL)
	{
		if (*printed == 1)
		{
			ft_printf(" ");
		}
		*printed = 1;
		room_index =
				(int)(long long)((t_node *)pp->ant_pos[cur_ant])->data;
		ft_printf("L%d-%s ", cur_ant + 1,
					((t_room *)rooms->data[room_index])->name);
		pp->ant_pos[cur_ant] = pp->ant_pos[cur_ant]->next;
	}
}

static void		move_ants(t_vector *rooms, int number_of_ants, t_pp *pp)
{
	int		cur_ant;
	int		printed;

	while (1)
	{
		printed = 0;
		cur_ant = 0;
		while (cur_ant < number_of_ants)
		{
			move_ants_internal(rooms, pp, cur_ant, &printed);
			++cur_ant;
		}
		if (!printed)
		{
			break ;
		}
		ft_printf("\n");
	}
}

void			print_paths(t_list *paths, t_vector *rooms,
					int number_of_ants)
{
	t_pp	pp;

	pp.ants_on_path = (int *)ft_memalloc(paths->size * sizeof(int));
	pp.ant_pos = (t_node **)ft_memalloc(number_of_ants * sizeof(t_node *));
	pp.ant_wait = (int *)ft_memalloc(number_of_ants * sizeof(int));
	if (pp.ants_on_path == NULL || pp.ant_pos == NULL || pp.ant_wait == NULL)
	{
		ft_throw(ALLOC_MSG, E_ALLOC);
	}
	sort_paths(paths);
	place_ants_on_paths(paths, number_of_ants, &pp);
	move_ants(rooms, number_of_ants, &pp);
	free(pp.ants_on_path);
	free(pp.ant_pos);
	free(pp.ant_wait);
}
