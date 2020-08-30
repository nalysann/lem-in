/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:51:09 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:51:10 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char		*found;
	const char		*p;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	while ((p = ft_strchr(s, c)))
	{
		found = p;
		s = p + 1;
	}
	return ((char *)found);
}
