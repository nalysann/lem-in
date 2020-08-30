/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_placeholder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:57:17 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:57:18 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_buffer.h"
#include "pf_handle_placeholder.h"
#include "pf_type_handlers.h"

#include "ft_string.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

static const t_type_handler		g_type_handlers[TYPES_SIZE + 1] =
{
	handle_char,
	handle_string,
	handle_pointer,
	handle_signed,
	handle_signed,
	handle_oct,
	handle_unsigned,
	handle_hex_lower,
	handle_hex_upper,
	handle_bin,
	handle_float,
	handle_percent,
	handle_invalid
};

static bool		is_zero(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (false);
	return (true);
}

static char		*handle_prefix(t_fields *fields, char *result)
{
	if (fields->type != 'c' && *result == '-')
	{
		ft_memmove(result, result + 1, ft_strlen(result));
		return ("-");
	}
	if ((fields->flags & FLAG_PLUS))
		return ("+");
	if ((fields->flags & FLAG_SPACE))
		return (" ");
	if ((fields->flags & FLAG_HASH) && fields->type == 'o' &&
		((ft_strcmp(result, "0") && fields->precision <= 0) ||
		(result[0] != '0')))
		return ("0");
	if ((fields->flags & FLAG_HASH) && fields->type == 'x' && !is_zero(result))
		return ("0x");
	if ((fields->flags & FLAG_HASH) && fields->type == 'X' && !is_zero(result))
		return ("0X");
	if ((fields->flags & FLAG_HASH) && fields->type == 'b' && !is_zero(result))
		return ("0b");
	return ("");
}

static int		print_result(t_fields *fields, char *result, t_buffer *buf)
{
	char	*prefix;
	int		len;
	int		i;

	prefix = handle_prefix(fields, result);
	len = ft_strlen(prefix) + ft_strlen(result);
	if (fields->type == 'c' && !*result)
		++len;
	if (ft_strlen(prefix) != 0 && (fields->flags & FLAG_ZERO) != 0)
		add_to_buffer(buf, prefix, ft_strlen(prefix));
	i = 0;
	if (fields->width > len && (fields->flags & FLAG_MINUS) == 0)
		while (i++ < fields->width - len)
			add_to_buffer(buf, (fields->flags & FLAG_ZERO) ? "0" : " ", 1);
	if (ft_strlen(prefix) != 0 && (fields->flags & FLAG_ZERO) == 0)
		add_to_buffer(buf, prefix, ft_strlen(prefix));
	if (fields->type == 'c' && !*result)
		add_to_buffer(buf, "", 1);
	add_to_buffer(buf, result, ft_strlen(result));
	if (fields->width > len && (fields->flags & FLAG_MINUS) != 0)
		while (i++ < fields->width - len)
			add_to_buffer(buf, " ", 1);
	return ((fields->width > len) ? fields->width : len);
}

int				print_placeholder(t_fields *fields, va_list ap, t_buffer *buf)
{
	int		ret;
	char	*result;

	result = g_type_handlers[ft_strchr(SUPPORTED_TYPES, fields->type) -
								SUPPORTED_TYPES](fields, ap);
	if (!result)
		return (-1);
	if (fields->type == 'f' &&
		(ft_strstr(result, "inf") || ft_strstr(result, "nan")))
		fields->flags &= ~FLAG_ZERO;
	if (fields->type == 'f' && ft_strstr(result, "nan"))
		fields->flags &= ~FLAG_PLUS & ~FLAG_SPACE;
	ret = print_result(fields, result, buf);
	free(result);
	return (ret);
}
