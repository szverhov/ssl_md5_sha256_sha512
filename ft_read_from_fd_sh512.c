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

static void		ft_inner_frrfs(int fd)
{
	g_rffs512.data[g_rffs512.data_count] = g_rffs512.buff[g_rffs512.j];
	if (fd == 0 && g_flags & 256)
	{
		g_str[g_str_i] = g_rffs512.buff[g_rffs512.j];
		g_str_i++;
	}
	g_rffs512.j++;
	g_rffs512.data_count++;
	g_start_count++;

}

int				ft_read_from_fd_sh512(int fd)
{
	g_rffs512.rd = 0;
	g_rffs512.data_count = 0;
	while ((g_rffs512.rd = read(fd, g_rffs512.buff, 128)) > 0)
	{
		g_rffs512.j = 0;
		while (g_rffs512.rd--)
		{
			ft_inner_frrfs(fd);
			if (g_rffs512.data_count == 128)
			{
				ft_start_hashing512(g_rffs512.data, g_rffs512.data_count);
				g_rffs512.data_count = 0;
				break ;
			}
		}
	}
	if (g_rffs512.data_count > 0)
		ft_start_hashing512(g_rffs512.data, g_rffs512.data_count);
	else if (g_start_count == 0 || g_start_count % 128 == 0)
		ft_start_hashing512((unsigned char*)"", 0);
	return (1);
}
