/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:53:08 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:53:10 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_buffer.h"

#include "ft_string.h"

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

static void		init_buffer(t_buffer *buf, bool *buf_initialized)
{
	buf->fd = STDOUT_FILENO;
	ft_strclr(buf->str);
	buf->len = 0;
	*buf_initialized = true;
}

void			flush_buffer(t_buffer *buf, int fd)
{
	write(buf->fd, buf->str, buf->len);
	buf->fd = fd;
	ft_strclr(buf->str);
	buf->len = 0;
}

void			check_buffer(t_buffer *buf, int fd)
{
	static bool		buf_initialized = false;

	if (!buf_initialized)
		init_buffer(buf, &buf_initialized);
	if (buf->fd != fd)
		flush_buffer(buf, fd);
}

void			add_to_buffer(t_buffer *buf, const char *str, size_t len)
{
	size_t	tmp;

	while (buf->len + len >= BUF_SIZE)
	{
		tmp = BUF_SIZE - buf->len;
		ft_memcpy(buf->str + buf->len, str, tmp);
		len -= tmp;
		str += tmp;
		buf->len = BUF_SIZE;
		flush_buffer(buf, buf->fd);
	}
	ft_memcpy(buf->str + buf->len, str, len);
	buf->len += len;
}
