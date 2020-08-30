/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:43:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:43:20 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	align_to_lword(unsigned char **dst, const unsigned char **src,
							size_t *n)
{
	unsigned char		*dst_;
	const unsigned char	*src_;

	dst_ = *dst;
	src_ = *src;
	while (*n && ((size_t)dst_ & (sizeof(unsigned long) - 1)))
	{
		*dst_++ = *src_++;
		--*n;
	}
	*dst = dst_;
	*src = src_;
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long		*dst_long;
	const unsigned long	*src_long;
	unsigned char		*dst_char;
	const unsigned char	*src_char;

	if (dst == src)
		return (dst);
	dst_char = (unsigned char *)dst;
	src_char = (const unsigned char *)src;
	align_to_lword(&dst_char, &src_char, &n);
	dst_long = (unsigned long *)dst_char;
	src_long = (const unsigned long *)src_char;
	while (n >= sizeof(unsigned long))
	{
		*dst_long++ = *src_long++;
		n -= sizeof(unsigned long);
	}
	dst_char = (unsigned char *)dst_long;
	src_char = (const unsigned char *)src_long;
	while (n--)
		*dst_char++ = *src_char++;
	return (dst);
}
