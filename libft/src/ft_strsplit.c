/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:51:21 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:51:22 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	words_count;

	words_count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			++words_count;
			while (*s && *s != c)
				++s;
		}
	}
	return (words_count);
}

static char		*get_word(const char **str, char c)
{
	size_t		len;
	const char	*beg;

	beg = *str;
	len = 0;
	while (**str && **str != c)
	{
		++len;
		++*str;
	}
	return (ft_strndup(beg, len));
}

static void		free_text(char **text, size_t size)
{
	while (size--)
		ft_memdel((void **)&text[size]);
	ft_memdel((void **)&text);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**text;
	char	*word;
	size_t	i;
	size_t	words_count;

	i = 0;
	words_count = count_words(s, c);
	if (!(text = malloc(sizeof(*text) * (words_count + 1))))
		return (NULL);
	while (i < words_count)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			if (!(word = get_word(&s, c)))
			{
				free_text(text, i);
				return (NULL);
			}
			text[i++] = word;
		}
	}
	text[i] = NULL;
	return (text);
}
