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

#include "parser.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_string.h"

#include <stddef.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}

void	save_line(t_list **input, char *line)
{
	t_list	*new_line;

	new_line = ft_lstnew(line, ft_strlen(line) + 1);
	if (new_line == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ft_lstadd_back(input, new_line);
	*input = (*input)->next;
}

void	parse(t_list **input, t_list **rooms, size_t *size, size_t *ants)
{
	parse_ants(input, ants);
	*size = parse_rooms(rooms, *input);

}