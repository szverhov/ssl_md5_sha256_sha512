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

void			ft_parse_flags(char **argv)
{
	ft_init_globals();
	if (!ft_strcmp(argv[1], "md5"))
		g_flags |= 1;
	if (!ft_strcmp(argv[1], "sha256"))
		g_flags |= 2;
	if (!ft_strcmp(argv[1], "sha512"))
		g_flags |= 4;
	while (argv[g_argvi])
	{
		if (!ft_strcmp(argv[g_argvi], "-p"))
			g_flags |= 256;
		else if (!ft_strcmp(argv[g_argvi], "-r"))
			g_flags |= 512;
		else if (!ft_strcmp(argv[g_argvi], "-s") && argv[g_argvi + 1] != 0)
			ft_save_index_of_word(g_argvi + 1);
		else if (!ft_strcmp(argv[g_argvi], "-q"))
			g_flags |= 2048;
		else
			break ;
		g_argvi++;
	}
}
