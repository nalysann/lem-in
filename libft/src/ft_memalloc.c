/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:42:26 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:42:27 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = NULL;
	if (size && (area = malloc(size)))
		ft_bzero(area, size);
	return (area);
}
