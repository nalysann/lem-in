/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:36:30 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/10 20:09:30 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "parse.h"
#include "path.h"
#include "solve.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"

#include <stddef.h>

static void		check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./lem-in          read map from stdin\n");
		ft_printf("       ./lem-in < map    use map specified in the file\n");
		ft_throw(NULL_MSG, E_NONE);
	}
}

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

int				main(int argc, char *argv[])
{
	t_list		input;
	int			number_of_ants;
	t_vector	rooms;
	t_dinic		info;
	t_list		*paths;

	check_args(argc, argv);
	list_init(&input);
	vector_init(&rooms);
	paths = NULL;
	parse(&input, &number_of_ants, &rooms, &info);
	print_input(&input);
	if (number_of_ants == 0)
		return (free_all(&input, &rooms, &info, paths));
	paths = dinic(&info, &rooms, number_of_ants);
	if (paths == NULL)
	{
		ft_throw(NO_PATHS_MSG, E_NO_PATHS);
	}
	ft_printf("\n");
	print_paths(paths, &rooms, number_of_ants);
	free_all(&input, &rooms, &info, paths);
}
