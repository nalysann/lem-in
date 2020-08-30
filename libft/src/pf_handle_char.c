/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:54:08 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:54:09 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_placeholder.h"

#include "ft_stdlib.h"

#include <stdarg.h>
#include <stddef.h>

char	*handle_char(t_fields *fields, va_list ap)
{
	char	*result;

	if (!(result = ft_strnew(1)))
		return (NULL);
	result[0] = (char)va_arg(ap, int);
	(void)fields;
	return (result);
}
