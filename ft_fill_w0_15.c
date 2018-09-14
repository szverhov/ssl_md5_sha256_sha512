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

void				ft_fill_w0_15()
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < 128)
	{
		g_sh512.w[i] = ((unsigned long long)(g_sh512.data[j]) << 56) |
		((unsigned long long)(g_sh512.data[j + 1]) << 48) |
		((unsigned long long)(g_sh512.data[j + 2]) << 40) |
		((unsigned long long)(g_sh512.data[j + 3])  << 32 | 
			g_sh512.data[j + 4] << 24) | (g_sh512.data[j + 5] << 16) |
			(g_sh512.data[j + 6 ] << 8) | (g_sh512.data[j + 7]);
		i++;
		j += 8;
	}
	g_sh512.w_i = 16;
}
