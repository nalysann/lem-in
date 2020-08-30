/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:50:08 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:50:09 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = ft_strnlen(src, n);
	if (len != n)
		ft_bzero(dst + len, n - len);
	return (ft_memcpy(dst, src, len));
}
