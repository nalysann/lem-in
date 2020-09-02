/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:57:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 12:57:05 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "ft_list.h"
# include "ft_vector.h"

# include <stddef.h>

void	parse(t_list *input, t_vector *rooms, size_t *ants);
void	parse_ants(t_list *input, size_t *number_of_ants);
char	*parse_rooms(t_list *input, t_vector *rooms);
void	parse_links(t_list *input, t_vector *rooms, char *line);

#endif
