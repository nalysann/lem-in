/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:53:00 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:53:01 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_bigint.h"

#include "ft_string.h"

unsigned long long	g_powers_of_five[] =
{
	1,
	5,
	25,
	125,
	625,
	3125,
	15625,
	78125,
	390625,
	1953125,
	9765625,
	48828125,
	244140625
};

void		bigint_add(t_bigint *this, t_bigint *other)
{
	unsigned			size;
	unsigned long long	sum;
	unsigned long long	carry;
	unsigned			i;

	size = (this->size > other->size ? this->size : other->size);
	carry = 0;
	i = 0;
	while (i < size)
	{
		sum = this->blocks[i] + other->blocks[i] + carry;
		this->blocks[i] = sum % BIGINT_BASE;
		carry = sum / BIGINT_BASE;
		++i;
	}
	this->blocks[i] = carry;
	this->size = (carry == 0 ? size : size + 1);
}

void		bigint_add_ull(t_bigint *this, unsigned long long other)
{
	unsigned long long	sum;
	unsigned long long	carry;
	unsigned			i;

	sum = this->blocks[0] + other;
	this->blocks[0] = sum % BIGINT_BASE;
	carry = sum / BIGINT_BASE;
	i = 1;
	while (carry != 0)
	{
		sum = this->blocks[i] + carry;
		this->blocks[i] = sum % BIGINT_BASE;
		carry = sum / BIGINT_BASE;
		++i;
	}
	if (i > this->size)
		this->size = i;
}

void		bigint_mul_ull(t_bigint *this, unsigned long long other)
{
	unsigned long long	product;
	unsigned long long	carry;
	unsigned			i;

	carry = 0;
	i = 0;
	while (i < this->size)
	{
		product = this->blocks[i] * other + carry;
		this->blocks[i] = product % BIGINT_BASE;
		carry = product / BIGINT_BASE;
		++i;
	}
	this->blocks[i] = carry;
	if (carry != 0)
		++(this->size);
}

void		bigint_power_of_five(t_bigint *this, unsigned power)
{
	ft_bzero(this, sizeof(*this));
	if (power <= 12)
	{
		this->blocks[0] = g_powers_of_five[power];
		this->size = 1;
		return ;
	}
	this->blocks[0] = 1ULL;
	this->size = 1;
	while (power > 0)
		if (power >= 12)
		{
			bigint_mul_ull(this, g_powers_of_five[12]);
			power -= 12;
		}
		else
		{
			bigint_mul_ull(this, g_powers_of_five[power]);
			power = 0;
		}
}
