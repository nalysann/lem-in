/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_placeholder.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:27:55 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:27:56 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_PLACEHOLDER_H
# define PF_HANDLE_PLACEHOLDER_H

# include "pf_buffer.h"

# include <stdarg.h>

# define SUPPORTED_FLAGS		"#0-+ "
# define FLAG_HASH				(1U << 0)
# define FLAG_ZERO				(1U << 1)
# define FLAG_MINUS				(1U << 2)
# define FLAG_PLUS				(1U << 3)
# define FLAG_SPACE				(1U << 4)

# define GET_DEFAULT			(-1)
# define GET_ARGUMENT			(-2)

# define ZERO_PRECISION			0
# define DEFAULT_PRECISION		6

# define LENGTH_MODIFIERS_SIZE	8
# define LENGTH_HH				(1U << 0)
# define LENGTH_H				(1U << 1)
# define LENGTH_LL_LOWER		(1U << 2)
# define LENGTH_L_LOWER			(1U << 3)
# define LENGTH_J				(1U << 4)
# define LENGTH_T				(1U << 5)
# define LENGTH_Z				(1U << 6)
# define LENGTH_L_UPPER			(1U << 7)
# define LENGTH_DEFAULT			(1U << 31)

# define TYPES_SIZE		 		12
# define SUPPORTED_TYPES		"cspdiouxXbf%"
# define INTEGER_TYPES			"diouxXb"
# define INVALID_TYPE			'\0'

# define BIN_DIGITS				"01"
# define OCT_DIGITS				"01234567"
# define DEC_DIGITS				"0123456789"
# define HEXL_DIGITS			"0123456789abcdef"
# define HEXU_DIGITS			"0123456789ABCDEF"

typedef struct	s_fields
{
	unsigned	flags;
	int			width;
	int			precision;
	unsigned	length;
	char		type;
}				t_fields;

typedef char	*(*t_type_handler)(t_fields *fields, va_list ap);

int				handle_placeholder(const char **format, va_list ap,
						t_buffer *buf);

#endif
