/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:21:39 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/11 17:11:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "solve.h"

# include "ft_list.h"
# include "ft_vector.h"

# include <stddef.h>

typedef struct	s_pp
{
	int		*ants_on_path;
	t_node	**ant_pos;
	int		*ant_wait;
}				t_pp;

t_list			*get_paths(t_vector *rooms, t_dinic *info);
double			count_turns(t_list *paths, int number_of_ants);

void			print_paths(t_list *paths, t_vector *rooms, int number_of_ants);

void			sort_paths(t_list *paths);

#endif
