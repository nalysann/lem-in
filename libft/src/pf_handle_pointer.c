/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:56:11 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:56:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_placeholder.h"
#include "pf_utils.h"

#include "ft_stdlib.h"
#include "ft_string.h"

#include <stdarg.h>
#include <stddef.h>

char	*handle_pointer(t_fields *fields, va_list ap)
{
	char *result;
	char str[42];

	itoa_base_unsigned((unsigned long)va_arg(ap, void *), HEXL_DIGITS, str);
	if (!(result = ft_strnew(ft_strlen(str) + 2)))
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	ft_strcpy(result + 2, str);
	(void)fields;
	return (result);
}
