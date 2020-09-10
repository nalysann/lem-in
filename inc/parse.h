/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:57:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/08 14:50:35 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "solve.h"

# include "ft_list.h"
# include "ft_vector.h"

# include <stddef.h>

void	parse(t_list *input, int *number_of_ants, t_vector *rooms,
				t_dinic *info);
void	parse_ants(t_list *input, int *number_of_ants);
char	*parse_rooms(t_list *input, t_vector *rooms, t_dinic *info);
void	parse_links(t_list *input, t_vector *rooms, char *line, t_dinic *info);

#endif
