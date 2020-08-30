/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:42:45 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:42:47 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void		*search_with_longwords(const unsigned char *char_ptr,
										unsigned char uc, size_t n)
{
	const unsigned long		*long_ptr;
	unsigned long			longword;
	unsigned long			mask;

	long_ptr = (unsigned long *)char_ptr;
	mask = 0x0101010101010101 * (unsigned long)uc;
	while (n >= sizeof(unsigned long))
	{
		longword = *long_ptr ^ mask;
		if (((longword - 0x0101010101010101) &
			~longword & 0x8080808080808080) != 0)
			break ;
		++long_ptr;
		n -= sizeof(unsigned long);
	}
	char_ptr = (const unsigned char *)long_ptr;
	while (n > 0)
	{
		if (*char_ptr == uc)
			return ((void *)char_ptr);
		--n;
		++char_ptr;
	}
	return (NULL);
}

void			*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*char_ptr;
	unsigned char			uc;

	uc = (unsigned char)c;
	char_ptr = (const unsigned char *)s;
	while (n > 0 && (((size_t)char_ptr & (sizeof(unsigned long) - 1))) != 0)
	{
		if (*char_ptr == uc)
			return ((void *)char_ptr);
		--n;
		++char_ptr;
	}
	return (search_with_longwords(char_ptr, uc, n));
}
