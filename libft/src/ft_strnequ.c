/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:50:31 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:50:32 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	return (ft_strncmp(s1, s2, n) == 0);
}
