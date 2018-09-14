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

static void		ft_inner0(t_rffs *sha, int fd)
{
	sha->j = 0;
	while (sha->rd--)
	{
		sha->data[sha->data_count] = sha->buff[sha->j];
		if (fd == 0 && g_flags & 256)
		{
			g_str[g_str_i] = sha->buff[sha->j];
			g_str_i++;
		}
		sha->j++;
		sha->data_count++;
		g_start_count++;
		if (sha->data_count == 64)
		{
			ft_start_256_encode(sha->data, sha->data_count);
			sha->data_count = 0;
			break ;
		}
	}
}

int				ft_read_from_fd_sh256(int fd)
{
	t_rffs sha;

	sha.rd = 0;
	sha.data_count = 0;
	while ((sha.rd = read(fd, sha.buff, 64)) > 0)
	{
		sha.j = 0;
		ft_inner0(&sha, fd);
	}
	if (sha.data_count > 0)
		ft_start_256_encode(sha.data, sha.data_count);
	else if (g_start_count == 0 || g_start_count % 64 == 0)
		ft_start_256_encode((unsigned char*)"", 0);
	return (1);
}
