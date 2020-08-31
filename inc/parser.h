/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:57:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 12:57:05 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_list.h"

# include <stddef.h>

void	parse(t_list **input, t_list **rooms, size_t *size, size_t *ants);
void	parse_ants(t_list **input, size_t *number_of_ants);
size_t	parse_rooms(t_list **rooms, t_list *input);
void	parse_links(t_list *rooms, t_list *input, char *line);

void	save_line(t_list **input, char *line);

#endif
