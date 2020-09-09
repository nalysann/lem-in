/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:04:54 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/08 14:04:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "room.h"
#include "solve.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_vector.h"

#include <stddef.h>

static void		sort_paths(t_list *paths)
{
	t_node	*node;
	t_node	*check;
	void	*tmp;

	node = paths->front;
	while (node != NULL)
	{
		check = node->next;
		while (check != NULL)
		{
			if (((t_list *)node->data)->size > ((t_list *)check->data)->size)
			{
				tmp = node->data;
				node->data = check->data;
				check->data = tmp;
			}
			check = check->next;
		}
		node = node->next;
	}
}

static void		place_ants_on_paths(t_list *paths, int number_of_ants, t_pp *pp)
{
	int		cur_ant;
	int		cur_path;
	t_node	*node;
	t_node	*next;

	cur_ant = 0;
	cur_path = 0;
	node = paths->front;
	while (cur_ant < number_of_ants)
	{
		while (node != NULL && node->next != NULL)
		{
			next = node->next;
			if (((t_list *)node->data)->size + pp->ants_on_path[cur_path] <=
				((t_list *)next->data)->size + pp->ants_on_path[cur_path + 1])
			{
				break;
			}
			++cur_path;
			node = node->next;
		}
		pp->ant_pos[cur_ant] = ((t_list *)node->data)->front;
		pp->ant_wait[cur_ant] = pp->ants_on_path[cur_path]++;
		++cur_ant;
	}
}

static void		move_ants(t_vector *rooms, int number_of_ants, t_pp *pp)
{
	int		cur_ant;
	int		room_index;
	int		printed;

	while (1)
	{
		printed = 0;
		cur_ant = 0;
		while (cur_ant < number_of_ants)
		{
			if (pp->ant_wait[cur_ant] != 0)
			{
				--pp->ant_wait[cur_ant];
			}
			else
			{
				if (pp->ant_pos[cur_ant] != NULL)
				{
					printed = 1;
					room_index = (int)(long long)((t_node *)pp->ant_pos[cur_ant])->data;
					ft_printf("L%d-%s ", cur_ant + 1, ((t_room *)rooms->data[room_index])->name);
					pp->ant_pos[cur_ant] = pp->ant_pos[cur_ant]->next;
				}
			}
			++cur_ant;
		}
		if (!printed)
			break ;
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
		ft_throw(ALLOC_MSG, E_ALLOC);
	sort_paths(paths);
	place_ants_on_paths(paths, number_of_ants, &pp);
	move_ants(rooms, number_of_ants, &pp);
}
