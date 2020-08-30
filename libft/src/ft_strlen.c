/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:48:57 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:48:58 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	count_with_longwords(const char *s, const char *char_ptr)
{
	const unsigned long		*long_ptr;
	unsigned long			longword;
	size_t					i;

	long_ptr = (unsigned long *)char_ptr;
	while (1)
	{
		longword = *long_ptr++;
		if ((((longword - 0x0101010101010101) &
			~longword & 0x8080808080808080)) != 0)
		{
			char_ptr = (const char *)(long_ptr - 1);
			i = 0;
			while (i < sizeof(unsigned long))
			{
				if (char_ptr[i] == '\0')
					return (char_ptr - s + i);
				++i;
			}
		}
	}
}

size_t		ft_strlen(const char *s)
{
	const char	*char_ptr;

	char_ptr = (const char *)s;
	while (((size_t)char_ptr & (sizeof(unsigned long) - 1)) != 0)
	{
		if (*char_ptr == '\0')
			return (char_ptr - s);
		++char_ptr;
	}
	return (count_with_longwords(s, char_ptr));
}
