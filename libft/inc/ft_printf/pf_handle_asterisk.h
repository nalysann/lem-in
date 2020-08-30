/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_asterisk.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:27:14 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:27:16 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_ASTERISK_H
# define PF_HANDLE_ASTERISK_H

# include "pf_handle_placeholder.h"

# include <stdarg.h>

void	handle_asterisk(t_fields *fields, va_list ap);

#endif
