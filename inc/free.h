/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:48:46 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/10 18:33:45 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "solve.h"

# include "ft_list.h"
# include "ft_vector.h"

void	free_path(void *data);
int		free_all(t_list *input, t_vector *rooms, t_dinic *info, t_list *paths);

#endif
