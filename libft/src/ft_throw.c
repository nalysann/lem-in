/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:52:13 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:52:21 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_stdio.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_throw(const char *error_message, int error_code)
{
	if (error_message != NULL)
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putstr_fd(error_message, STDERR_FILENO);
		ft_putendl_fd(WHITE, STDERR_FILENO);
	}
	exit(error_code);
}
