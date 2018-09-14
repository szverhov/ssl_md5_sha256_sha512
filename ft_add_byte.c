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

void				ft_add_byte(unsigned long long byte, unsigned long long reserv)
{
	g_sh512.tmp = (unsigned char*)malloc(sizeof(unsigned char)
	* (g_sh512.data_len + 1));
	g_sh512.i = -1;
	while (++(g_sh512.i) < g_sh512.data_len)
		g_sh512.tmp[g_sh512.i] = g_sh512.data[g_sh512.i];
	g_sh512.tmp[g_sh512.i] = (unsigned char)byte;
	if (reserv == 7)
		g_sh512.b_len = g_sh512.data_len * 8 + 1;
	g_sh512.b_reserv = reserv;
	g_sh512.data_len++;
	free(g_sh512.data);
	g_sh512.data = g_sh512.tmp;
}
