/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:57:38 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:57:39 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_math.h"
#include "ft_string.h"

#include <stddef.h>

void	ft_atoi_skip(const char **str)
{
	if (**str == '+' || **str == '-')
		++(*str);
	while (ft_isdigit(**str))
		++(*str);
}

size_t	get_length_signed(long long nbr, long long base)
{
	size_t	length;

	length = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		++length;
		nbr /= base;
	}
	return (length);
}

void	itoa_base_signed(long long nbr, const char *base_digits,
						char *result)
{
	long long	base;
	size_t		number_length;
	size_t		sign;

	base = ft_strlen(base_digits);
	number_length = get_length_signed(nbr, base);
	sign = (nbr < 0 ? 1 : 0);
	result[number_length] = '\0';
	while (number_length > sign)
	{
		result[--number_length] = base_digits[ft_llabs(nbr % base)];
		nbr /= base;
	}
	if (sign != 0)
		result[--number_length] = '-';
}

size_t	get_length_unsigned(unsigned long long nbr, unsigned long long base)
{
	size_t	length;

	length = (nbr == 0 ? 1 : 0);
	while (nbr != 0)
	{
		++length;
		nbr /= base;
	}
	return (length);
}

void	itoa_base_unsigned(unsigned long long nbr,
							const char *base_digits, char *result)
{
	unsigned long long	base;
	size_t				number_length;

	base = ft_strlen(base_digits);
	number_length = get_length_unsigned(nbr, base);
	result[number_length] = '\0';
	while (number_length != 0)
	{
		result[--number_length] = base_digits[nbr % base];
		nbr /= base;
	}
}
