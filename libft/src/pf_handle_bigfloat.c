/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_bigfloat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:53:30 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:53:31 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_bigint.h"
#include "pf_handle_bigfloat.h"
#include "pf_handle_placeholder.h"
#include "pf_utils.h"

#include "ft_string.h"

static void		print_block(t_bigint *bi, t_string *fractional,
								int *precision, int i)
{
	unsigned int	base;
	int				k;

	if ((base = 1) && i == (int)bi->size - 1)
	{
		k = get_length_unsigned(bi->blocks[i], 10);
		while (--k)
			base = base * 10;
	}
	else
		base = 100000000;
	if (((unsigned)i != bi->size - 1 && *precision < BIGINT_BLOCK_SIZE) ||
		(*precision < (int)get_length_unsigned(bi->blocks[i], 10) &&
		(unsigned)i == bi->size - 1))
		while ((*precision)-- > 0)
		{
			if (base != 0 && (bi->blocks[i] / base) % 10 == 0)
				fractional->str[(fractional->len)++] = '0';
			else if (base != 0)
				fractional->str[(fractional->len)++] =
						(bi->blocks[i] / base) % 10 + '0';
			base /= 10;
		}
	else
		ulltoa(bi->blocks[i], fractional);
}

void			moar_precision(t_bigint *bi, t_string *fractional,
									int *precision, int i)
{
	int		j;

	while (i >= 0 && *precision > 0)
	{
		j = BIGINT_BLOCK_SIZE - get_length_unsigned(bi->blocks[i], 10);
		if ((unsigned)i == bi->size - 1)
			j = 0;
		while (j > 0 && *precision >= BIGINT_BLOCK_SIZE)
		{
			fractional->str[(fractional->len)++] = '0';
			--j;
		}
		print_block(bi, fractional, precision, i);
		if ((unsigned)i == bi->size - 1)
			*precision -= get_length_unsigned(bi->blocks[i], 10);
		else
			*precision -= BIGINT_BLOCK_SIZE;
		--i;
	}
	if (*precision > 0)
		fractional->str[(fractional->len)++] = '0';
	--(*precision);
}

void			print_leading_zeros(t_bigfloat *bf, t_fields *fields,
								int *precision, t_string *fractional)
{
	unsigned	zeros;

	fractional->str[(fractional->len)++] = '.';
	++(fields->precision);
	*precision = fields->precision;
	zeros = count_leading_zeros(bf);
	while (zeros > 0 && *precision > 0)
	{
		fractional->str[(fractional->len)++] = '0';
		--zeros;
		--(*precision);
	}
}

void			print_decimal_part(t_bigfloat *bf, t_string *decimal)
{
	int		i;
	int		j;

	i = bf->decimal.size - 1;
	while (i >= 0)
	{
		j = BIGINT_BLOCK_SIZE - get_length_unsigned(bf->decimal.blocks[i], 10);
		if ((unsigned)i != bf->decimal.size - 1)
		{
			while (j > 0)
			{
				decimal->str[(decimal->len)++] = '0';
				--j;
			}
		}
		ulltoa(bf->decimal.blocks[i], decimal);
		--i;
	}
}

void			print_float(t_string *decimal, t_string *fractional,
							t_fields *fields, char *result)
{
	unsigned	len;

	if (fractional->len == 1 && (fields->flags & FLAG_HASH) == 0)
		fractional->len = 0;
	ft_memcpy(result, decimal->str, decimal->len);
	len = decimal->len;
	ft_memcpy(result + len, fractional->str, fractional->len);
	len += fractional->len;
	while (fields->precision >= 0)
	{
		ft_memcpy(result + len, "0", 1);
		--(fields->precision);
		++len;
	}
	result[len] = '\0';
}
