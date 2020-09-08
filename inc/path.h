/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:21:39 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/30 19:21:39 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "solve.h"

# include "ft_list.h"
# include "ft_vector.h"

# include <stddef.h>

typedef struct	s_path
{
	t_list	rooms;
	size_t	ants;
}				t_path;

t_list			*get_paths(t_vector *rooms, t_dinic *info);
double			count_turns(t_list *paths, int number_of_ants);

#endif
