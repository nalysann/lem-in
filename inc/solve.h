/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 07:47:10 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/03 07:47:11 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "ft_list.h"
# include "ft_vector.h"

# define NOT_VISITED	(-1)

typedef struct	s_edge
{
	int		from;
	int		to;
	int		cap;
	int		flow;
}				t_edge;

typedef struct	s_dinic
{
	t_vector	edges;
	int			*d;
	t_node		**last;
	int			n;
	int			s;
	int			t;
}				t_dinic;

int				dinic(t_dinic *info, t_vector *rooms);

#endif
