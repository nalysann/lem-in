/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:49:25 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:49:28 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

#include <stddef.h>

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if ((!*s1 && !*s2) || ft_tolower(*s1++) != ft_tolower(*s2++))
			return ((const unsigned char)ft_tolower(*(s1 - 1)) -
					(const unsigned char)ft_tolower(*(s2 - 1)));
	}
	return (0);
}
