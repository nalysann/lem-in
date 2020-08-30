/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:44:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:44:10 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	align_to_lword(unsigned char **ptr, unsigned char uc, size_t *n)
{
	unsigned char	*char_ptr;

	char_ptr = *ptr;
	while (*n && ((size_t)char_ptr & (sizeof(unsigned long) - 1)))
	{
		*char_ptr++ = uc;
		--*n;
	}
	*ptr = char_ptr;
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*char_ptr;
	unsigned long	*long_ptr;
	unsigned char	uc;
	unsigned long	repeated_uc;

	char_ptr = (unsigned char *)b;
	uc = (unsigned char)c;
	align_to_lword(&char_ptr, uc, &len);
	long_ptr = (unsigned long *)char_ptr;
	repeated_uc = 0x0101010101010101 * (unsigned long)uc;
	while (len >= sizeof(unsigned long))
	{
		*long_ptr++ = repeated_uc;
		len -= sizeof(unsigned long);
	}
	char_ptr = (unsigned char *)long_ptr;
	while (len--)
		*char_ptr++ = uc;
	return (b);
}
