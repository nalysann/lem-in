/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:39:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/31 11:39:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "ft_list.h"

# include <stddef.h>

# define NULL_MSG		NULL
# define ERROR_MSG		"ERROR: unknown error"
# define ALLOC_MSG		"ERROR: memory allocation failed"
# define LINE_MSG		"ERROR: invalid line"
# define ANT_MSG		"ERROR: invalid number of ants"
# define ROOM_MSG		"ERROR: invalid room"
# define LINK_MSG		"ERROR: invalid link"
# define START_MSG		"ERROR: next line after ##start must be a valid room"
# define STOP_MSG		"ERROR: next line after ##stop must be a valid room"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2

void	print_node(t_list *node);
size_t	count_words(char **words);

#endif
