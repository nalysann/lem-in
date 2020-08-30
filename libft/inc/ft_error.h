/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:30:11 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:30:13 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# ifndef WHITE
#  define WHITE		"\033[0;0m"
# endif

# ifndef RED
#  define RED		"\033[1;31m"
# endif

void	ft_throw(const char *error_message, int error_code);

#endif
