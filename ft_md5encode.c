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

int				ft_md5encode(char **argv)
{
	unsigned int		rd;
	
	rd = 0;
	if ((!(g_flags & 1024) && argv[g_argvi] == 0) || g_flags & 256)
	{
		ft_read_from_fd(0);
		ft_encoded_to_str(g_md5.a, g_md5.b , g_md5.c , g_md5.d);
	}
	if (g_flags & 1024)
		ft_read_data_from_argv(argv);
	if (argv[g_argvi])
		ft_read_data_from_files(argv);
	return (1);
}
