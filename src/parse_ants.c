/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:08:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/08 13:39:52 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include "ft_error.h"
#include "ft_list.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"

#include <limits.h>
#include <unistd.h>

void	parse_ants(t_list *input, int *number_of_ants)
{
	char		*line;
	long long	number;
	char		*endptr;

	if (get_next_line(STDIN_FILENO, &line) <= 0)
		ft_throw(ANT_MSG, E_INPUT);
	while (line[0] == '#' && line[1] != '#')
		get_next_line(STDIN_FILENO, &line);
	list_push_back(input, line);
	number = ft_strtoll(line, &endptr, 10);
	if (line[0] == '\0' || endptr[0] != '\0' ||
		!(0 <= number && number <= INT_MAX))
		ft_throw(ANT_MSG, E_INPUT);
	*number_of_ants = (int)number;
}
