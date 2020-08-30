/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:47:11 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:47:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	void	*new;

	len = ft_strlen(s) + 1;
	if (!(new = malloc(len)))
		return (NULL);
	return (ft_memcpy(new, s, len));
}
