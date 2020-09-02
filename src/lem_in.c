/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:36:30 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/01 13:46:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_vector.h"

#include <stddef.h>

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
	t_vector	rooms;
	size_t	ants;

	list_init(&input);
	vector_init(&rooms);
	parse(&input, &rooms, &ants);
	print_input(&input);
//	solve(rooms, size, ants);
}
