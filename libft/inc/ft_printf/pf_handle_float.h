/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_float.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:27:33 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:27:39 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_FLOAT_H
# define PF_HANDLE_FLOAT_H

# include "pf_handle_placeholder.h"

# include <stdarg.h>

# define EXPONENT_SHIFT		16383

typedef union				u_extended
{
	long double				value;
	struct
	{
		unsigned long long	mantissa : 64;
		unsigned			exponent : 15;
		unsigned			sign : 1;
	}						s_;
}							t_extended;

char						*handle_float(t_fields *fields, va_list ap);

#endif
