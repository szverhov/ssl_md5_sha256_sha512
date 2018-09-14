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
		write(1, "SH256 (\"", 8);
		write(1, g_s_word, ft_strlen(g_s_word));
		write(1, "\") = ", 5);
	}

	if (g_fl_or_str == 2 && !(g_flags & 2048) && !(g_flags & 512))
	{
		write(1, "SH256 (", 8);
		write(1, g_f_name, ft_strlen(g_f_name));
		write(1, ") = ", 4);
	}
}

static void		ft_post_format()
{
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

static void		ft_print(unsigned char tmp, int j, int shift, int i)
{
	while (++j < 8)
	{
		i = -1;
		if (j == 0)
			g_ev.h0 = g_ev.h0;
		if (j == 1)
			g_ev.h0 = g_ev.h1;
		if (j == 2)
			g_ev.h0 = g_ev.h2;
		if (j == 3)
			g_ev.h0 = g_ev.h3;
		if (j == 4)
			g_ev.h0 = g_ev.h4;
		if (j == 5)
			g_ev.h0 = g_ev.h5;
		if (j == 6)
			g_ev.h0 = g_ev.h6;
		if (j == 7)
			g_ev.h0 = g_ev.h7;
		while (++i < 4)
			ft_print_hexa_uchar((tmp = 0 | g_ev.h0 >> (shift -= 8)));
	}
}

void			ft_print_hash()
{
	g_str[g_str_i] = 0;
	ft_pre_format();
	ft_print(0, -1, 32, -1);
	ft_post_format();
}
