/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:53:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:53:21 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_placeholder.h"

#include "ft_string.h"

#include <stdarg.h>

static void		handle_asterisk_width(t_fields *fields, va_list ap)
{
	if (fields->width == GET_ARGUMENT)
	{
		fields->width = va_arg(ap, int);
		if (fields->width < 0)
		{
			fields->width *= -1;
			fields->flags |= FLAG_MINUS;
		}
	}
}

static void		handle_asterisk_precision(t_fields *fields, va_list ap)
{
	if (fields->precision == GET_ARGUMENT)
	{
		fields->precision = va_arg(ap, int);
		if (fields->precision < 0)
			fields->precision = GET_DEFAULT;
		if (ft_strchr(INTEGER_TYPES, fields->type) &&
			fields->precision != GET_DEFAULT)
			fields->flags &= ~FLAG_ZERO;
	}
}

void			handle_asterisk(t_fields *fields, va_list ap)
{
	handle_asterisk_width(fields, ap);
	handle_asterisk_precision(fields, ap);
}
