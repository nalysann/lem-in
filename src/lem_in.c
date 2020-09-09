/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:36:30 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/08 13:35:12 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "parse.h"
#include "solve.h"

#include "ft_list.h"
#include "ft_stdio.h"

#include <stddef.h>

#include "ft_stdio.h"

static void		print_input(t_list *input)
{
	t_node	*node;

	if (input->size == 0)
		return ;
	node = input->front;
	while (node != NULL)
	{
		ft_printf("%s\n", node->data);
		node = node->next;
	}
}

int				main(void)
{
	t_list		input;
	int			number_of_ants;
	t_vector	rooms;
	t_dinic		info;
	t_list		*paths;

	list_init(&input);
	vector_init(&rooms);
	paths = NULL;
	parse(&input, &number_of_ants, &rooms, &info);
	print_input(&input);
	paths = dinic(&info, &rooms, number_of_ants);
	ft_printf("\n");
	t_node	*nnn = (t_node *)paths->front;
	while (nnn != NULL)
	{
		t_list *path = (t_list *)nnn->data;
		ft_printf("%lu ", path->size);
		nnn = nnn->next;
	}
	ft_printf("\n");
//	print_answer(map, paths, ants + 1, flow);
}
