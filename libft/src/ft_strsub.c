/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:51:39 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:51:41 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (len == SIZE_MAX || !(substr = malloc(len + 1)))
		return (NULL);
	substr[len] = '\0';
	return (ft_strncpy(substr, s + start, len));
}
