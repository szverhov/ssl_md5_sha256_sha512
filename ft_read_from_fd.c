/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.ff                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by szverhov          #+#    #+#             */
/*   Updated: 0000/00/00 00:00:00 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

typedef struct	s_rff
{
	int				rd;
	unsigned int	data_count;
	unsigned char	buff[64];
	unsigned char	data[64];
	unsigned int	j;	
}				t_rff;

static void		ft_inner0(t_rff *m5, int fd)
{
	m5->j = 0;
	while (m5->rd--)
	{
		m5->data[m5->data_count] = m5->buff[m5->j];
		if (fd == 0 && g_flags & 256)
		{
			g_str[g_str_i] = m5->buff[m5->j];
			g_str_i++;
		}
		m5->j++;
		m5->data_count++;
		g_md5.len++;
		if (m5->data_count == 64)
		{
			ft_start_encode(m5->data, m5->data_count * 8);
			m5->data_count = 0;
			break ;
		}			
	}
}

int				ft_read_from_fd(int fd)
{
	t_rff m5;

	m5.rd = 0;
	m5.data_count = 0;
	while ((m5.rd = read(fd, m5.buff, 64)) > 0)
		ft_inner0(&m5, fd);
	if (m5.data_count > 0)
		ft_start_encode(m5.data, m5.data_count * 8);
	else if (g_md5.len == 0 || g_md5.len % 64 == 0)
		ft_start_encode((unsigned char*)"", m5.data_count * 8);
	return (1);
}
