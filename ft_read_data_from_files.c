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

static void		ft_no_file_or_dir(char **argv)
{
	ECHO("ft_ssl: md5: ");
	ECHO(argv[g_argvi]);
	ECHO(": No such file or directory\n");
	g_argvi++;	
}

void			ft_read_data_from_files(char **argv)
{
	int		fd;
	char	buff[1];

	g_fl_or_str = 2;
	while (argv[g_argvi])
	{
		if ((fd = open(argv[g_argvi], O_RDONLY)) < 0)
		{
			ft_no_file_or_dir(argv);
			continue ;
		}
		if (read(fd, buff ,0) < 0)
		{
			ECHO("ft_ssl: md5: ");
			ECHO(argv[g_argvi]);
			ECHO(": cant read directory\n");
			g_argvi++;
			continue ;
		}
		ft_read_from_fd(fd);
		g_f_name = argv[g_argvi];
		ft_encoded_to_str(g_md5.a, g_md5.b , g_md5.c , g_md5.d);
		g_argvi++;
	}
}
