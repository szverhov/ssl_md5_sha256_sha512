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

static void		ft_pre_format()
{
	g_str[g_str_i] = 0;
	if (g_flags & 256)
	{
		write(1, g_str, g_str_i);
		g_flags ^= 256;
	}
	if (g_fl_or_str == 1 && !(g_flags & 2048) && !(g_flags & 512))
	{
		write(1, "MD5 (\"", 6);
		write(1, g_s_word, ft_strlen(g_s_word));
		write(1, "\") = ", 5);
	}

	if (g_fl_or_str == 2 && !(g_flags & 2048) && !(g_flags & 512))
	{
		write(1, "MD5 (", 5);
		write(1, g_f_name, ft_strlen(g_f_name));
		write(1, ") = ", 4);
	}
}

static void		ft_post_format()
{
	g_md5.a = A;
	g_md5.b = B;
	g_md5.c = C;
	g_md5.d = D;
	g_md5.len = 0;
	if (g_fl_or_str == 1 && !(g_flags & 2048) && (g_flags & 512))
	{
		write(1, " \"", 2);
		write(1, g_s_word, ft_strlen(g_s_word));
		write(1, "\"", 2);
	}
	if (g_fl_or_str == 2 && !(g_flags & 2048) && (g_flags & 512))
	{
		write(1, " ", 1);
		write(1, g_f_name, ft_strlen(g_f_name));
	}
	write(1, "\n", 1);
}

int				ft_encoded_to_str(unsigned int a,
	unsigned int b, unsigned int c, unsigned int d)
{
	unsigned char	tmp;
	int				i;
	int				shift;
	int				j;

	ft_pre_format();
	shift = -8;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		if (j == 1)
			a = b;
		if (j == 2)
			a = c;
		if (j == 3)
			a = d;
		while (++i < 4)
			ft_print_hexa_uchar((tmp = 0 | a >> (shift += 8)));
	}
	ft_post_format();
	return (1);
}
