/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:55:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:55:20 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_placeholder.h"

#include <inttypes.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/types.h>

long long			get_signed(va_list ap, unsigned int length)
{
	if (length & LENGTH_HH)
		return ((char)va_arg(ap, int));
	if (length & LENGTH_H)
		return ((short)va_arg(ap, int));
	if (length & LENGTH_L_LOWER)
		return (va_arg(ap, long));
	if (length & LENGTH_LL_LOWER)
		return (va_arg(ap, long long));
	if (length & LENGTH_J)
		return (va_arg(ap, intmax_t));
	if (length & LENGTH_T)
		return (va_arg(ap, ptrdiff_t));
	if (length & LENGTH_Z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

unsigned long long	get_unsigned(va_list ap, unsigned int length)
{
	if (length & LENGTH_HH)
		return ((unsigned char)va_arg(ap, unsigned));
	if (length & LENGTH_H)
		return ((unsigned short)va_arg(ap, unsigned));
	if (length & LENGTH_L_LOWER)
		return (va_arg(ap, unsigned long));
	if (length & LENGTH_LL_LOWER)
		return (va_arg(ap, unsigned long long));
	if (length & LENGTH_J)
		return (va_arg(ap, uintmax_t));
	if (length & LENGTH_T)
		return (va_arg(ap, size_t));
	if (length & LENGTH_Z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned));
}

long double			get_float(va_list ap, unsigned int length)
{
	if (length & LENGTH_L_LOWER)
		return (va_arg(ap, double));
	if (length & LENGTH_L_UPPER)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}
