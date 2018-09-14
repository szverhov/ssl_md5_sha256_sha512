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

void				ft_append_len512()
{
	g_sh512.tmp = (unsigned char*)malloc(sizeof(unsigned char) * (g_sh512.data_len + 16));
	g_sh512.i = -1;
	g_sh512.strt_ln *= 8;
	while (++(g_sh512.i) < g_sh512.data_len)
		g_sh512.tmp[g_sh512.i] = g_sh512.data[g_sh512.i];
	g_sh512.tmp[g_sh512.i] = 0;
	g_sh512.tmp[g_sh512.i + 1] = 0;
	g_sh512.tmp[g_sh512.i + 2] = 0;
	g_sh512.tmp[g_sh512.i + 3] = 0;
	g_sh512.tmp[g_sh512.i + 4] = 0;
	g_sh512.tmp[g_sh512.i + 5] = 0;
	g_sh512.tmp[g_sh512.i + 6] = 0;
	g_sh512.tmp[g_sh512.i + 7] = 0;
	g_sh512.tmp[g_sh512.i + 8] = g_sh512.zero | g_sh512.strt_ln >> 56;
	g_sh512.tmp[g_sh512.i + 9] = g_sh512.zero | g_sh512.strt_ln >> 48;
	g_sh512.tmp[g_sh512.i + 10] = g_sh512.zero | g_sh512.strt_ln >> 40;
	g_sh512.tmp[g_sh512.i + 11] = g_sh512.zero | g_sh512.strt_ln >> 32;
	g_sh512.tmp[g_sh512.i + 12] = g_sh512.zero | g_sh512.strt_ln >> 24;
	g_sh512.tmp[g_sh512.i + 13] = g_sh512.zero | g_sh512.strt_ln >> 16;
	g_sh512.tmp[g_sh512.i + 14] = g_sh512.zero | g_sh512.strt_ln >> 8;
	g_sh512.tmp[g_sh512.i + 15] = g_sh512.zero | g_sh512.strt_ln;
	g_sh512.data_len += 16;
	g_sh512.b_len += 128;
	free(g_sh512.data);
	g_sh512.data = g_sh512.tmp;
}
