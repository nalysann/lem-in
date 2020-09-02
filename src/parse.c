/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:31:58 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 11:31:59 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_vector.h"

#include <stddef.h>

#include "ft_stdio.h"

void	parse(t_list *input, t_vector *rooms, size_t *ants)
{
	char	*line;

	parse_ants(input, ants);
	line = parse_rooms(input, rooms);
	parse_links(input, rooms, line);
}