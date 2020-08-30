/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:50:40 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:50:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

#include <stddef.h>
#include <stdint.h>

char	*ft_strnew(size_t size)
{
	return ((size == SIZE_MAX) ? NULL : ft_memalloc(size + 1));
}
