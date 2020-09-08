/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:03:36 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 18:03:38 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"

#include "ft_string.h"
#include "ft_vector.h"

#include <stddef.h>

size_t	count_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i] != NULL)
		++i;
	return (i);
}

int		get_room_index_by_type(t_vector *rooms, t_room_type type, char half)
{
	int		i;
	t_room	*room;

	i = 0;
	while (i < (int)rooms->size)
	{
		room = (t_room *)rooms->data[i];
		if (room->type == type)
		{
			break ;
		}
		i += 2;
	}
	return (half == 'i' ? i : i + 1);
}

int		get_room_index_by_name(t_vector *rooms, char *name, char half)
{
	int		i;
	t_room	*room;

	i = 0;
	while (i < (int)rooms->size)
	{
		room = (t_room *)rooms->data[i];
		if (ft_strequ(room->name, name))
		{
			break ;
		}
		i += 2;
	}
	return (half == 'i' ? i : i + 1);
}
