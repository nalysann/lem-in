/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_placeholder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:55:55 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:55:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_buffer.h"
#include "pf_handle_asterisk.h"
#include "pf_handle_placeholder.h"
#include "pf_print_placeholder.h"
#include "pf_read_fields.h"

#include "ft_string.h"

#include <stdarg.h>

static void		read_fields(const char **format, t_fields *fields)
{
	read_flags(format, fields);
	read_width(format, fields);
	read_precision(format, fields);
	read_length(format, fields);
	read_type(format, fields);
}

static void		fix_fields(t_fields *fields)
{
	if (fields->flags & FLAG_PLUS)
		fields->flags &= ~FLAG_SPACE;
	if (ft_strchr(INTEGER_TYPES, fields->type) &&
		fields->precision != GET_DEFAULT)
		fields->flags &= ~FLAG_ZERO;
	if ((fields->type == 'f' || fields->type == 'e' || fields->type == 'E') &&
		fields->precision == GET_DEFAULT)
		fields->precision = DEFAULT_PRECISION;
}

int				handle_placeholder(const char **format, va_list ap,
									t_buffer *buf)
{
	t_fields	fields;

	++(*format);
	ft_bzero(&fields, sizeof(t_fields));
	read_fields(format, &fields);
	handle_asterisk(&fields, ap);
	fix_fields(&fields);
	return (print_placeholder(&fields, ap, buf));
}
