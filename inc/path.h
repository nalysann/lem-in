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

# include "ft_list.h"

# include <stddef.h>

typedef struct	s_path
{
	t_list	*rooms;
	size_t	length;
	size_t	ants;
}				t_path;

#endif
