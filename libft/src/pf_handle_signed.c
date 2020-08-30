/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:56:33 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:56:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_length.h"
#include "pf_handle_placeholder.h"
#include "pf_utils.h"

#include "ft_stdlib.h"
#include "ft_string.h"

#include <stdarg.h>
#include <stddef.h>

char	*handle_signed(t_fields *fields, va_list ap)
{
	char	*result;
	char	str[42];
	int		len;
	int		zeros;
	int		sign;

	itoa_base_signed(get_signed(ap, fields->length), DEC_DIGITS, str);
	len = ft_strlen(str);
	sign = (*str == '-' ? 1 : 0);
	if (len == 1 && *str == '0' && fields->precision == 0)
		return (ft_strnew(0));
	if (fields->precision > len - sign)
		result = ft_strnew(60 + fields->precision + sign);
	else
		result = ft_strnew(60 + len);
	if (!result)
		return (NULL);
	ft_strcpy(result, str);
	zeros = fields->precision - (len - sign);
	if (fields->precision != GET_DEFAULT && zeros > 0)
	{
		ft_memmove(result + sign + zeros, result + sign, len - sign + 1);
		ft_memset(result + sign, '0', zeros);
	}
	return (result);
}
