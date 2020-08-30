/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_fields.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:57:27 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:57:30 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_placeholder.h"
#include "pf_utils.h"

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void	read_flags(const char **format, t_fields *fields)
{
	const char	*ptr;

	while (**format != '\0')
	{
		ptr = ft_strchr(SUPPORTED_FLAGS, **format);
		if (ptr)
		{
			fields->flags |= (1U << (ptr - SUPPORTED_FLAGS));
			++(*format);
		}
		else
			break ;
	}
}

void	read_width(const char **format, t_fields *fields)
{
	if (**format == '*')
	{
		fields->width = GET_ARGUMENT;
		++(*format);
	}
	else if (ft_isdigit(**format))
	{
		fields->width = ft_atoi(*format);
		ft_atoi_skip(format);
	}
	else
		fields->width = GET_DEFAULT;
}

void	read_precision(const char **format, t_fields *fields)
{
	if (**format == '.')
	{
		++(*format);
		if (**format == '*')
		{
			fields->precision = GET_ARGUMENT;
			++(*format);
		}
		else if (ft_isdigit(**format))
		{
			fields->precision = ft_atoi(*format);
			ft_atoi_skip(format);
		}
		else
			fields->precision = ZERO_PRECISION;
	}
	else
		fields->precision = GET_DEFAULT;
}

void	read_length(const char **format, t_fields *fields)
{
	const char *const	length_modifiers[LENGTH_MODIFIERS_SIZE] = {
			"hh", "h", "ll", "l", "j", "t", "z", "L"};
	int					i;
	char				*ptr;

	i = 0;
	while (i < LENGTH_MODIFIERS_SIZE)
	{
		ptr = ft_strnstr(*format, length_modifiers[i],
						ft_strlen(length_modifiers[i]));
		if (ptr)
		{
			fields->length = (1U << i);
			*format += ft_strlen(length_modifiers[i]);
			return ;
		}
		++i;
	}
	fields->length = LENGTH_DEFAULT;
}

void	read_type(const char **format, t_fields *fields)
{
	char	*ptr;

	if (**format != '\0')
	{
		ptr = ft_strchr(SUPPORTED_TYPES, **format);
		if (ptr)
		{
			fields->type = SUPPORTED_TYPES[ptr - SUPPORTED_TYPES];
			++(*format);
		}
	}
	else
		fields->type = INVALID_TYPE;
}
