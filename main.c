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

int				main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "Choose type of hashing\n", 23);
		return (0);
	}
	ft_parse_flags(argv);
	if (g_flags & 1)
		ft_md5encode(argv);
	else if (g_flags & 2)
		ft_sha256encode(argv);
	else if (g_flags & 4)
		ft_sha512encode(argv);
	else
		write(1, "Wrong hashing type!\n", 20);
	// if (g_flags & 4)
	// 	ft_sha512encode(argv);
	// system("leaks --quiet ft_ssl_md5");
	return (0);
}
