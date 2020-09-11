/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:42:10 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:11:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stddef.h>

void	sort_paths(t_list *paths)
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
