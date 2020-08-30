/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:45:57 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:45:59 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	while (*s1 && (ft_tolower(*s1) == ft_tolower(*s2)))
	{
		++s1;
		++s2;
	}
	return ((const unsigned char)ft_tolower(*s1) -
			(const unsigned char)ft_tolower(*s2));
}
