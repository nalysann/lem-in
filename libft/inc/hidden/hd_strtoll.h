/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_strtoll.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:29:55 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:29:56 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_STRTOLL_H
# define HD_STRTOLL_H

typedef struct	s_strtoll
{
	const char			*str;
	int					base;
	int					sign;
	int					c;
	int					any;
	unsigned long long	res;
}				t_strtoll;

#endif
