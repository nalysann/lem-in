/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:36:30 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/30 19:36:31 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"

#include <stddef.h>

void	print_node(t_list *node)
{
	ft_printf("%s\n", (char *)node->content);
}

int		main(void)
{
	t_list	*input;
	t_list	*rooms;
	size_t	size;
	size_t	ants;

	input = NULL;
	rooms = NULL;
	parse(&input, &rooms, &size, &ants);
	ft_lstiter(input, print_node);
//	evaluate(rooms, input, size, ants);
}
