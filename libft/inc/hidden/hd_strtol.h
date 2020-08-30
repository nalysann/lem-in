/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_strtol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:29:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:29:49 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_STRTOL_H
# define HD_STRTOL_H

typedef struct	s_strtol
{
	const char		*str;
	int				base;
	int				sign;
	int				c;
	int				any;
	unsigned long	res;
}				t_strtol;

#endif
