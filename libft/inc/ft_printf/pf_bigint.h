/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:26:56 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:27:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_BIGINT_H
# define PF_BIGINT_H

# include <stddef.h>

# define BIGINT_BASE		1000000000
# define BIGINT_MAX_BLOCKS	1300
# define BIGINT_BLOCK_SIZE	9

typedef struct	s_bigint
{
	unsigned long long	blocks[BIGINT_MAX_BLOCKS];
	unsigned			size;
}				t_bigint;

typedef struct	s_string
{
	char		str[BIGINT_MAX_BLOCKS * BIGINT_BLOCK_SIZE];
	unsigned	len;
}				t_string;

void			bigint_add(t_bigint *this, t_bigint *other);
void			bigint_add_ull(t_bigint *this, unsigned long long other);
void			bigint_mul_ull(t_bigint *this, unsigned long long other);
void			bigint_power_of_five(t_bigint *this, unsigned power);

#endif
