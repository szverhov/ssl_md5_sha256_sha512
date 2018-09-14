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

void			ft_sha256encode(char **argv)
{
	if ((!(g_flags & 1024) && argv[g_argvi] == 0) || g_flags & 256)
	{
		ft_init_encode_vars();
		ft_read_from_fd_sh256(0);
		ft_print_hash();
	}
	if (g_flags & 1024)
	{
		ft_init_encode_vars();
		ft_read_data_from_argv_sh256(argv);
	}
	if (argv[g_argvi])
	{
		ft_init_encode_vars();
		ft_read_data_from_files_sh256(argv);
	}
}
