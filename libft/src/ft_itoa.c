/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:38:31 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:38:52 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <stddef.h>
#include <stdlib.h>

static size_t	get_length(int n)
{
	size_t	len;

	len = (n <= 0 ? 1 : 0);
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	sign;
	char	*str;

	sign = (n < 0 ? 1 : 0);
	len = get_length(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > sign)
	{
		str[--len] = (char)('0' + ft_abs(n % 10));
		n /= 10;
	}
	if (sign != 0)
		str[--len] = '-';
	return (str);
}
