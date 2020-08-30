/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:51:49 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:51:51 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "hd_strtol.h"

#include <errno.h>
#include <limits.h>
#include <stddef.h>

static void	skip(t_strtol *s)
{
	while (ft_isspace(s->c))
		s->c = *(s->str)++;
	s->sign = (s->c == '-' ? -1 : 1);
	if (s->c == '+' || s->c == '-')
		s->c = *(s->str)++;
	if ((s->base == 0 || s->base == 16) && s->c == '0' &&
		(*(s->str) == 'x' || *(s->str) == 'X'))
	{
		s->c = s->str[1];
		s->str += 2;
		s->base = 16;
	}
	if (s->base == 0)
		s->base = (s->c == '0' ? 8 : 10);
}

static void	convert_main(t_strtol *s, unsigned long cutoff, int cutlim)
{
	while (1)
	{
		if (ft_isdigit(s->c))
			s->c -= '0';
		else if (ft_isalpha(s->c))
			s->c -= (ft_isupper(s->c) ? 'A' - 10 : 'a' - 10);
		else
			break ;
		if (s->c >= s->base)
			break ;
		if (s->any < 0 ||
			s->res > cutoff || (s->res == cutoff && s->c > cutlim))
		{
			s->any = -1;
		}
		else
		{
			s->any = 1;
			s->res = s->res * s->base + s->c;
		}
		s->c = *(s->str)++;
	}
}

static void	convert(t_strtol *s)
{
	unsigned long	cutoff;
	int				cutlim;

	cutoff = (s->sign < 0 ? -(LONG_MIN / s->base) : LONG_MAX / s->base);
	cutlim = (s->sign < 0 ? -(LONG_MIN % s->base) : LONG_MAX % s->base);
	convert_main(s, cutoff, cutlim);
}

long		ft_strtol(const char *str, char **endptr, int base)
{
	t_strtol	s;

	s.str = str;
	s.base = base;
	s.c = ' ';
	s.any = 0;
	s.res = 0;
	if (!(base == 0 || (2 <= base && base <= 36)))
	{
		errno = EINVAL;
		return ((long)s.res);
	}
	skip(&s);
	convert(&s);
	if (endptr != NULL)
		*endptr = (char *)(s.any != 0 ? s.str - 1 : str);
	if (s.any < 0)
	{
		errno = ERANGE;
		return (s.sign < 0 ? LONG_MIN : LONG_MAX);
	}
	return ((long)(s.sign < 0 ? -s.res : s.res));
}
