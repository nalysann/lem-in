/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_placeholder.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:28:03 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:28:04 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_PLACEHOLDER_H
# define PF_PRINT_PLACEHOLDER_H

# include "pf_buffer.h"
# include "pf_handle_placeholder.h"

# include <stdarg.h>

int		print_placeholder(t_fields *fields, va_list ap, t_buffer *buf);

#endif
